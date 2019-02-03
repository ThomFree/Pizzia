# [EN] Medium : Simple Auth
## Description
The purpose of this example is to show you how to make a **simple authentication using GET params**. It will check if the `username` and `password` GET parameters are equals than `foo` and `bar` and display page in case of failure / success with associated HTTP status.

This example uses 3 modules :
- RequestParserModule : Parse everything that is in the ```getRaw()``` of the ```IRequest```. It parses : URI parameters, HTTP headers, HTTP method, HTTP version, URI and the body.
- SimpleAuthModule : This module make body and status according to authentication credentials validity provided in GET parameters.
- ResponseMakerModule : This is the final module that convert everything in ```IResponse``` and call the ```setRaw()``` method.
## Pipeline
The pipeline is not very complicated, but it is crucial that every module is called one after another.
<p align="center">
  <img src="https://i.imgur.com/vsyi3sR.png">
</p>

## Expected result
If there is missing required parameter (`username` or `password`), the output is the following error message with `422 Unprocessable Entity` status:

<p align="center">
  <img src="https://i.imgur.com/cKezUnh.png">
</p>

If there there is an error with credentials, the output is the following error message with `401 Unauthorized` status:

<p align="center">
  <img src="https://i.imgur.com/S08XeUE.png">
</p>

If the credentials are good, the output is the following with `200 OK` status:
<p align="center">
  <img src="https://i.imgur.com/vhd6ZDN.png">
</p>

# [FR] Intermédiaire: Simple Auth
## Description
Le but de cet exemple et de vous montrer **une authentification très simple**. Cet exemple va vérifier si les paramètrs GET `username` et `password` sont respectivement égaux à `foo` et `bar` et afficher une page HTML en fonction du résultat avec également un statut approprié au résultat.
Cet exemple utilise trois modules :
- RequestParserModule : Traite toutes les données qui se trouvent dans ```getRaw()``` de ```IRequest```. Il traite l'URI, les paramètres URI, les en-têtes HTTP, la méthode HTTP ainsi que la version et le contenu de la page (body).
- SimpleAuthModule : Ce module fabrique un contenu de page et un status en fonction de la validité des identifiants fournis en paramètres GET.
- ResponseMakerModule : C'est le module finale, il convertit tout le contenu de ```IResponse``` en chaîne de caractère et appelle la méthode ```setRaw()```.
## Pipeline
Si jamais il y a un paramètre manquant (`username` ou `password) le résultat est celui ci-dessous avec le statut suivant: `422 Unprocessable Entity`:

<p align="center">
  <img src="https://i.imgur.com/cKezUnh.png">
</p>

Si les identifiants sont incorrects, le résultat est celui ci-dessous avec le statut suivant: `401 Unauthorized`:

<p align="center">
  <img src="https://i.imgur.com/S08XeUE.png">
</p>

Enfin, si les identifiants sont corrects, le résultat est celui ci-dessous avec le statut suivant `200 OK`:
<p align="center">
  <img src="https://i.imgur.com/vhd6ZDN.png">
</p>