## A TCP client in C

Description commande				|	Commande						|	Réponse		|	Description réponse
----------------------------------- | --------------------------------- | ------------- | -------------------------------
Authentification					|	/auth [prénom]:[nom]\n			|	/ok\n		|	Authentification réussie
Liste des habitants					|	/list\n							|				|	Envoi la liste des habitants de Trantor*
Message de Hari Seldon				|	/hs\n							|				|	Envoi un message de Hari Seldon
Qu'est-ce que la psychohistoire ?	|	/psychohistory\n				|				|	Définition de la notion
Statut habitant						|	/getstatus [prénom]:[nom]\n		|				|	Envoi le statut de l'habitant
Afficher infos personnelles			|	/me\n							|				|	Envoi information de l'utilisateur authentifié
Changer son statut					|	/setstatus [nouveau statut]\n	|	/ok\n		|	Changement de statut