// Copyright © 2008 Pippijn van Steenhoven
#include <cstdlib>

namespace rio
{
  namespace allocators
  {
    struct system
    {
      static void *allocate (std::size_t bytes)
      {
        return std::malloc (bytes);
      }
      
      static void deallocate (void *ptr, std::size_t bytes)
      {
        std::free (ptr);
      }
    };

    struct executable
    {
      static void *allocate (std::size_t bytes)
      {
        return mmap (0, bytes, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
      }
      
      static void deallocate (void *ptr, std::size_t bytes)
      {
        munmap (ptr, bytes);
      }
    };
  }
}
