# CGI vs PHP

> Some very basic benchmarking

# Why?

I wanted to see if CGI was faster than PHP.

# What?

A basic test between different level of optimizations in C compiled for CGI vs the exact same logic in a PHP script.

# How?

*Notes:*
* You'll need `sudo` access for `make install`
* You can tweak your values in `Makefile` (at the top)

```bash
cd cgi-vs-php
make compile
make install
make test
```

# What Was Supposed To Happen?

CGI was supposed to be faster than PHP :(

# What Actually Happened?

I haven't uploaded any of my results, because I want to make sure that I'm not messing up the data - but preliminary results indicate that PHP is considerably faster than CGI. At least on a default Apache setup on Linux Mint 19 (x64 5.11 kernel).

I really just want to confirm my bias - so I'll massage the data and Apache configuration until that happens.
