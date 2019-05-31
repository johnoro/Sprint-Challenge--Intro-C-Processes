**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- R: running or runnable process
- D: process in an uninterruptible sleep (cannot be killed)
- S: process in an interruptible sleep (waiting for an event to complete)
- Z: zombie (terminated process whose status hasn't been collected by its parent)
- T: suspended process

Did we go over these in any sort of depth during lecture or during any of our reading? I recall most, if not all, of the focus being on the Z state.

**2. What is a zombie process?**

A terminated process whose status hasn't been collected by its parent.

**3. How does a zombie process get created? How does one get destroyed?**

A zombie process gets destroyed by its parent reading the child's exit status via the `wait` syscall.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

There is typically a performance benefit due to the compilation (since it compiles to something closer to the hardware). The extra time also allows for compilers to optimize our code, depending on their implementations.
