./figlio.sh &

trap "echo; exit 0" SIGUSR2;

#è obbligatorio che il padre faccia qualcosa in attesa del figlio
while true; do
    echo -n ".";
    sleep 1;
done