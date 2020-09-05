tests: tests.c gen_qsort.o
	$(CC) tests.c gen_qsort.o -o $@ -lm

gen_qsort.o:  gen_qsort.c gen_qsort.h
	$(CC) -c -g $<

clean:
	rm *.o
