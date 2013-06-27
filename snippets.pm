package snippets;

use strict;
use warnings FATAL => 'all';
use utf8;

my $snippets;

my %fltops = (
   '+'  => "addition",
   '-'  => "subtraction",
   '%'  => "modulo division",
   '/'  => "division",
   '*'  => "multiplication",
   '**' => "power",
);
my %intops = (
   '|' => "bitwise OR",
   '^' => "bitwise XOR",
   '&' => "bitwise AND",
   '<<' => "left shift",
   '>>' => "right shift",
);
my %binops = (%fltops, %intops);

my %unops = (
   '+' => "identity",
   '-' => "negative",
   '~' => "bitwise complement",
);

sub constexpr {
   my ($var) = @_;
   sub {
      my @array = map { "prolog (2 $_ $var)" } keys %binops;
      push @array, (
         "prolog ($var)",
      );
      \@array
   }
}

for (keys %binops) {
   push @$snippets, (
      {
         code => ["prolog (2 $_ 3.2)"],
         msg => "cannot mix floating point and integral in operands to binary $binops{$_} operator",
      },
      {
         code => ["prolog (1 $_ )"],
         msg => "expected integral constant as rhs of binary $binops{$_} operator",
      },
      {
         code => ["prolog ( $_ )"],
         msg => "expected numeric constant before binary $binops{$_} operator",
      },
      {
         code => ["300 => $_"],
         msg => "operators are invalid as receiving operand of assignments",
      },
   )
}

for (keys %fltops) {
   push @$snippets, (
      {
         code => ["prolog (2.3 $_ 3)"],
         msg => "cannot mix floating point and integral in operands to binary $fltops{$_} operator",
      },
      {
         code => ["prolog (1.3 $_ )"],
         msg => "expected floating point constant as rhs of binary $binops{$_} operator",
      },
   )
}

for (keys %unops) {
   push @$snippets, (
      {
         code => ["prolog ( $_ )"],
         msg => "expected numeric constant after unary $unops{$_} operator",
      },
   )
}

for (keys %intops) {
   push @$snippets, (
      {
         code => ["prolog (2.3 $_ 2.3)"],
         msg => "cannot apply binary $intops{$_} operator to floating point constants",
      },
   )
}

push @$snippets, (
   {
      code => constexpr ('!a'),
      msg => 'compile-time function call cannot occur in constant expression',
   },
   {
      code => constexpr ('*a'),
      msg => 'function reference cannot occur in constant expression',
   },
   {
      code => constexpr ('&a'),
      msg => 'floating point variable cannot occur in constant expression',
   },
   {
      code => constexpr ('$a'),
      msg => 'integer variable cannot occur in constant expression',
   },
   {
      code => constexpr ('@a'),
      msg => 'instruction reference cannot occur in constant expression',
   },
   {
      code => ["prolog ()"],
      msg => "expected expression before ')' token",
   },
   {
      code => sub {
         my @array =  map { "prolog (2 $_ )" } keys %binops;
         \@array
      },
      msg => "expected integral constant before ')' token",
   },
   {
      code => sub {
         my @array =  map { "prolog (2.3 $_ )" } keys %fltops;
         \@array
      },
      msg => "expected floating point constant before ')' token",
   },
   {
      code => [
         "prolog (3   2.3)",
         "prolog (2.3 3)",
      ],
      msg => "expected operator before numeric constant",
   },
   {
      code => [
         '300 => 300',
         '300 => 300.3',
         '300 => !a',
         '300 => *a',
      ],
      msg => "lvalue required as receiving operand of assignment",
   },
   {
      code => [
         '300 => %r0',
         '300 => %v0',
         '300 => %fpr0',
         '300 => %ret',
         '300 => %sp',
         '300 => %fp',
      ],
      msg => "cannot assign to a register directly, use one of the mov instructions",
   },
   {
      code => ["prolog ()\0"],
      msg => "no newline at end of file",
   },
);

$snippets
