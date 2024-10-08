# Projet Philosophers - École 42

## Description
Le projet Philosophers est une introduction aux concepts de programmation concurrente et de synchronisation entre threads. Il s'inspire du célèbre problème du dîner des philosophes, proposé par Edsger Dijkstra en 1965 pour illustrer les défis de la synchronisation dans les systèmes d'exploitation.

## Objectifs
- Comprendre et implémenter la programmation multi-thread
- Gérer la synchronisation entre threads pour éviter les conditions de course
- Résoudre le problème classique du dîner des philosophes
- Optimiser l'utilisation des ressources système

## Le problème des philosophes
N philosophes sont assis autour d'une table ronde. Il y a une fourchette entre chaque philosophe. Les philosophes alternent entre trois états : manger, penser, ou dormir. Pour manger, un philosophe doit utiliser les deux fourchettes adjacentes. Le défi est d'implémenter une solution qui évite les deadlocks et les famines.

## Fonctionnalités
- Simulation du dîner des philosophes avec un nombre variable de philosophes
- Gestion du temps pour manger, dormir et penser
- Mécanismes de synchronisation pour éviter les deadlocks
- Monitoring de l'état de chaque philosophe
- Arrêt de la simulation si un philosophe meurt de faim

## Compétences développées
- Programmation multi-thread en C
- Utilisation de mutex et de sémaphores
- Gestion de la concurrence et de la synchronisation
- Optimisation des performances
- Débogage de programmes concurrents

## Installation et utilisation
1. Clonez ce dépôt :
   ```
   git clone https://github.com/thed6bel/philosophers.git
   ```
2. Naviguez dans le dossier du projet :
   ```
   cd philosophers
   ```
3. Compilez le projet :
   ```
   make
   ```
4. Lancez le programme avec les arguments appropriés :
   ```
   ./philo [nombre_de_philosophes] [temps_pour_mourir] [temps_pour_manger] [temps_pour_dormir] [nombre_de_repas_optionnel]
   ```
   Exemple :
   ```
   ./philo 5 800 200 200 7
   ```

## Arguments du programme
1. nombre_de_philosophes : Le nombre de philosophes et de fourchettes
2. temps_pour_mourir (en millisecondes) : Si un philosophe n'a pas commencé à manger temps_pour_mourir millisecondes après le début de son dernier repas ou le début de la simulation, il meurt
3. temps_pour_manger (en millisecondes) : Le temps qu'il faut à un philosophe pour manger
4. temps_pour_dormir (en millisecondes) : Le temps qu'un philosophe passera à dormir
5. nombre_de_repas (optionnel) : Si spécifié, la simulation s'arrête quand tous les philosophes ont mangé au moins nombre_de_repas fois. Sinon, la simulation s'arrête à la mort d'un philosophe.
