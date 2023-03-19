CC=gcc
CFLAGS=-g

demo_gestiunea_memoriei: demo_gestiunea_memoriei.c
	$(CC) $(CFLAGS) $^ -o $@

bonus: demo_gestiunea_memoriei.c
	$(CC) $(CFLAGS) -DBONUS $^ -o $@

clean:
	rm demo_gestiunea_memoriei bonus
