### Nei commenti iche seguono vedete dei suggerimenti sull'algoritmo da
### seguire per produrre l'output corretto.
###
# I voti della seconda prova li devo mettere tutti nello standard output

cat esame2.txt

#stampo esame tranne quelli già visti

while read matricola voto ; do 
	
	if [[ "`grep "${matricola} " ./esame2.txt`" == "" ]] ; then
	
		echo "1. ${matricola} ${voto}"
		
	fi
	

done < esame1.txt

# Poi devo mettere nello standard output i voti della prima prova
# ottenuti dagli studenti che non hanno un voto nella seconda prova


