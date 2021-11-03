sleep 5;

kill -SIGUSR2 ${PPID};

exit 0;