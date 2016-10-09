/*
 * Copyright (c) 2016, Scott Cheloha <scottcheloha@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* fizzbuzz.c -- A FizzBuzz implementation for BSD. */

#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

void
usage(int unused)
{
	(void)unused;
	fprintf(stderr, "usage: fizzbuzz n\n");
}

int
main(int argc, char **argv)
{
	int i, n;

	/*
	 * Validate user input.
	 */

	err_set_exit(usage);

	if (argc < 2)
		errx(EX_USAGE, "missing argument");

	n = atoi(argv[1]);
	if (errno != 0)
		err(EX_USAGE, "cannot convert \"%s\" to an integer", argv[1]);
	else if (n < 0)
		errx(EX_USAGE, "cannot accept %d: use a nonnegative value", n);

	if (argc > 2)
		warnx("ignoring extra argument \"%s\"", argv[2]);

	/*
	 * The FizzBuzz print loop.
	 */

	for (i = 1; i < n+1; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			if (i % 3 == 0)
				(void)printf("Fizz");
			if (i % 5 == 0)
				(void)printf("Buzz");
		} else
			(void)printf("%d", i);
		(void)printf("\n");
	}

	return (0);
}
