# [FR] Hard: Dé-chiffrement / Chiffrement
## Description
Le but de cet exemple et de vous présenter **un déchiffrement et un chiffrement** au sein même de la **pipeline** afin de vous apporter les bases pour réaliser vos modules de support HTTPS (par exemple). 

Nous avons utilisé le [cipher Caesar](https://en.wikipedia.org/wiki/Caesar_cipher) afin de vous présenter un algorithme simple, le but étant de comprendre comment vont agir les modules de dé-chiffrement de la requête et de chiffrement de la réponse au sein de la pipeline.

Cet exemple utilise cinq modules :

- **DecryptionModule** : Il va s'occuper de dé-chiffrer la requête brûte **chiffrée** (récupérée en utilisant `getRaw`, qui provient directement des données lues sur le socket) en utilisant le [cipher Caesar](https://en.wikipedia.org/wiki/Caesar_cipher). Dans notre exemple, la clef utilisée est: `n=42`. Une fois la requête dé-chiffrée, il va la modifier (en utilisant `setRaw`) pour que les prochains modules aient accès à la requête en claire. 
- **RequestParserModule** : Traite toutes les données qui se trouvent dans ```getRaw()``` de ```IRequest```. Il traite l'URI, les paramètres URI, les en-têtes HTTP, la méthode HTTP ainsi que la version et le contenu de la page (body).
- **RequestDebuggerModule** : Ce module fabrique un contenu de page contenant toutes les données de la requête.
- **ResponseMakerModule :** Ce module convertit tout le contenu de ```IResponse``` en chaîne de caractère et appel la méthode ```setRaw()```. Il s'agit en quelque sorte d'un module de **serialization**, l'opposé du **RequestParserModule** qui est un module de **parsing**.
- **EncryptionModule** : Il va s'occuper de chiffrer la réponse brûte (récupérée en utilisant `getRaw` et fabriquée par le module **ResponseMakerModule** s'éxécutant juste avant) en utilisant le [cipher Caesar](https://en.wikipedia.org/wiki/Caesar_cipher). Dans notre exemple, la clef utilisée est: `n=42`. Une fois la réponse chiffrée, il va la modifier (en utilisant `setRaw`) pour qu'elle soit transmise sur la socket de manière **chiffrée** (et en théorie sécurisée, enfin pas avec Caesar :/). 

## Pipeline
L'ordre dans lequel vont s'éxécuter les modules est essentiel. Le premier module de dé-chiffrement va permettre aux modules suivant d'avoir accès à la requête en **clair**, et le dernier module de chiffrement va permettre de chiffrer la réponse lors de l'envoi sur le socket.

<center><img src="https://i.imgur.com/OLucFA4.png"></center>


## Résultat attendu
Le résultat attendu n'est pas affichable par le navigateur (effectivement, la réponse étant chiffrée avec un algorithme inconnu du navigateur), nous utilisons **netcat** pour afficher directement ce qui est renvoyé par le serveur:

<center><img src="https://i.imgur.com/bvz6xbA.png"/></center>

Il s'agit bien de la response chiffrée.