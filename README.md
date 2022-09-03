# C/C++ Docker Dev Environment

An isolated Docker Development Environment for building C/C++ Apps.

## Use

### From outside the container/dev-environment

**Compile and run service interactively:**

_`docker compose build console && docker compose run --rm console`_

### Inside the dev-environment

**Compile and run:**

_`mkdir -p /app/build && cd /app/build && cmake .. && make && ./src/main && cd -`_

**Clear source files and binaries:**

_`make clean`_

## Folder structure

There is a _`./src`_ directory which contains the _`.c`_ source files and an _`./include`_ directory which contains the _`.h`_ headers files.

_`main.c`_ file is in _`./src/core/main`_ directory

Everything is a module, so in _`./src`_ and _`./include`_ everything is organized within folders according to that.
