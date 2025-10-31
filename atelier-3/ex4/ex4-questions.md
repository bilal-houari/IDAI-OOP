#### 1. Quelle est la différence entre une **copie superficielle** et une **copie profonde** dans ce contexte ?

*   **Copie Superficielle :** Le pointeur est copié ; les deux objets partagent la même ressource (`Client`), risquant la double suppression ou les pointeurs non valides.
*   **Copie Profonde :** Une nouvelle ressource (`Client`) est allouée et copiée. Les deux objets sont complètement indépendants et possèdent leurs propres ressources.

#### 2. Pourquoi le compteur du nombre de comptes doit-il être **statique** ?

Il doit être statique pour suivre une propriété de la **classe** entière (le nombre total de toutes les instances) plutôt que d'être un attribut propre à chaque objet individuel.

#### 3. Quelle est la différence entre une **méthode statique** et une **méthode normale** ?

*   **Méthode Normale (Instance) :** Nécessite une instance (objet) pour être appelée, reçoit le pointeur `this` et peut accéder aux membres de l'instance.
*   **Méthode Statique (Classe) :** Appartient à la classe, ne reçoit pas `this`, peut être appelée sans instance et accède uniquement aux membres statiques.

#### 4. Dans quels cas est-il pertinent de rendre une fonction **inline** ?

Lorsque la fonction est **petite, simple et appelée fréquemment**. Cela suggère au compilateur de remplacer l'appel de fonction par le corps du code pour éliminer la surcharge d'exécution et améliorer la performance.

#### 5. Que se passe-t-il si vous oubliez de libérer la mémoire dans le destructeur (spécifiquement concernant le `Client*` dans la classe `Account`) ?

Cela provoque une **fuite de mémoire (memory leak)** : la mémoire allouée sur le tas (heap) pour l'objet `Client` n'est pas libérée et reste inaccessible, ce qui peut mener à l'épuisement des ressources.