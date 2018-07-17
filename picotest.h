/*
 * Copyright (c) 2014 DeNA Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#ifndef picotest_h
#define picotest_h

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__GNUC__) /* GCC and clang support format attribute */
#define PICOTEST_PRINTF_ATTRIBUTE(a,b) __attribute__((format (printf, a, b)))
#else
#define PICOTEST_PRINTF_ATTRIBUTE(a,b)
#endif

void note(const char *fmt, ...)  PICOTEST_PRINTF_ATTRIBUTE(1, 2);
void _ok(int cond, const char *fmt, ...) PICOTEST_PRINTF_ATTRIBUTE(2, 3);
#define ok(cond) _ok(cond, "%s %d", __FILE__, __LINE__)
int done_testing(void);
void subtest(const char *name, void (*cb)(void));

#ifdef __cplusplus
}
#endif

#endif
