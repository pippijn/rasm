#ifndef INITIALLY_H_INCLUDED
#define INITIALLY_H_INCLUDED

#define P_(a, b)        a ## b

#define P2(a,b)         P_ (a, b)
#define P3(a,b,c)       P2 (a, P2 (b, c))
#define P4(a,b,c,d)     P2 (a, P3 (b, c, d))
#define P5(a,b,c,d,e)   P2 (a, P4 (b, c, d, e))
#define P6(a,b,c,d,e,f) P2 (a, P5 (b, c, d, e, f))

#define initially       for (static bool initialised = false; !initialised; initialised = true)
#define after(n)        static int P4 (after_, n, _on_, __LINE__) = 1; while (P4 (after_, n, _on_, __LINE__)++ == n)

#endif /* INITIALLY_H_INCLUDED */
