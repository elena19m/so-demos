CC=gcc

demo_gestiunea_memoriei: demo_gestiunea_memoriei.c
	$(CC) $^ -o $@

bonus: demo_gestiunea_memoriei.c
	$(CC) -DBONUS $^ -o $@

clean:
	rm demo_gestiunea_memoriei bonus
