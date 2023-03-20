CC=gcc
CFLAGS=-g

demo_gestiunea_memoriei: demo_gestiunea_memoriei.c
	$(CC) $(CFLAGS) $^ -o $@

bonus: demo_gestiunea_memoriei.c
	$(CC) $(CFLAGS) -DBONUS $^ -o $@

const: const.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f demo_gestiunea_memoriei bonus const
