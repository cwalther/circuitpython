/* This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (c) 2022-2023 Damien P. George
 */

#include "port/micropython_embed.h"

// This is example 1 script, which will be compiled and executed.
static const char *example_1 =
    "print('hello world!', [x + 1 for x in range(32)], end='eol\\n')";

// This is example 2 script, which will be compiled and executed.
static const char *example_2 =
    "for i in range(10):\n"
    "    print('iter {:08}'.format(i))\n"
    "\n"
    "try:\n"
    "    1//0\n"
    "except Exception as er:\n"
    "    print('caught exception', repr(er))\n"
    "\n"
    "import gc\n"
    "print('run GC collect')\n"
    "gc.collect()\n"
    "\n"
    "def f(x):\n"
    "    print('hello world!', 'f', x)\n"
    "def g(x):\n"
    "    print('hello world!', 'g', x)\n"
    "def h(x):\n"
    "    print('hello world!', 'h', x)\n"
    "def i(x):\n"
    "    print('hello world!', 'i', x)\n"
    "def j(x):\n"
    "    print('hello world!', 'j', x)\n"
    "def k(x):\n"
    "    print('hello world!', 'k', x)\n"
    "def l(x):\n"
    "    print('hello world!', 'l', x)\n"
    "f(1)\n"
    "f(2)\n"
    "f(3)\n"
    "f(4)\n"
    "f(5)\n"
    "f(6)\n"
    "f(7)\n"
    "f(8)\n"
    "f(9)\n"
    "f(10)\n"
    "f(11)\n"
    "f(12)\n"
    "f(13)\n"
    "f(14)\n"
    "f(15)\n"
    "f(16)\n"
    "f(17)\n"
    "f(18)\n"
    "f(19)\n"
    "f(20)\n"
    "print('finish')\n"
    ;

// This array is the MicroPython GC heap.
static char heap[8 * 1024];

int main() {
    // Initialise MicroPython.
    mp_embed_init(&heap[0], sizeof(heap));

    // Run the example scripts (they will be compiled first).
    mp_embed_exec_str(example_1);
    mp_embed_exec_str(example_2);

    // Deinitialise MicroPython.
    mp_embed_deinit();

    return 0;
}
