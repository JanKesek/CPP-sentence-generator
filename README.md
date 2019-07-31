# C-sentence-generator-

I used free Princeton University word-base https://wordnet.princeton.edu/download. Various unix utilities (awk,sed, egrep) are used to parsing and extracting text from files. Words are grouped into pairs
 <part-of-speach>: list
where list consists of single word or <part-of-speach> (where part-of-speach is: verb,noun,noun.location,adjective)
at the end of text file there is simple pair that looks like:
<sentence> : something
It represents structure of sentence. Feel free to experiment with other types structures of sentences. After cloning project compile with: 
```
g++ -o go sentencegenerator.cpp
```
Shoutout to 'Accelerated C++" which was inspiration

