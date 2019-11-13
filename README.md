# ft_printf
My replication of printf for 42 school.

Support `cCsSpdiuoxXnfge%` conversion.

Support `- 0.*#+` modifier flags.

Support `l ll h hh` size flags.

# Tester
![alt text](https://raw.githubusercontent.com/untel/ft_printf/master/test/demo.png)

This tester require an implementation of `s_printf(const char *buffer, ...);` to work.

Copy test folder into your own repository, and cd in.

Run `make run` to run all tests, with leaks check.

Run `make ARGS="int uint char string pointer hex float exp gfloat leaks other" run` to run only some tests.
