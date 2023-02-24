# Push_swap

Projet Ecole 42 :

Algorithme de tri basé sur "diviser pour régner". Nous avons 2 stacks (a et b) et nous devons trier dans l'ordre croissant dans la stack a, 
avec le moins d'instructions possibles les nombres donner en paramètres (idealement moins de 700 coups pour une liste de 100 nombres 
et moins de 5500 pour une liste de 500 nombres).

Les instructions disponibles sont : swap (echanger les 2 premiers nombres d'une stack), rotate(basculer le nombre de la première place à la dernière),
reverse_rotate(basculer le dernier nombre à la première) et le push (pour basculer les nombres d'une stack à l'autre).

- de 2 à 5 : algorithme effectuant un swap, un reverse rotate ou un rotate en fonction de l'emplacement du nombre max et du nombre min.
- de 6 a 200 chiffres : division par 3, trouver le N min pour chaque paquet divisé et envoyer les nombres inférieurs à ce N minimum dans b.
                        Une fois fait pour chaque paquet divisé, repush dans a en ayant au préalable placé la valeur la plus grande en première position.
- supérieur à 200 : division par 7, idem que la précédemment.

![image](https://user-images.githubusercontent.com/88725985/220952015-596fce02-45a9-4b8b-bd03-a32f93f521b7.png)
