# Guide Complet : Détection d’Objets sur STM32N6570-DK

**Auteur :** Abdalla  
**Contexte :** Projet réalisé au FabLab Valrose (Université Côte d’Azur) dans le cadre du Master 2 ESTEL

Ce dépôt est un **guide complet et francophone** pour la prise en main du kit de développement **STM32N6570-DK**, avec un focus particulier sur l’**Intelligence Artificielle embarquée** et la **détection de personnes**.

Il intègre et enrichit le [dépôt officiel de STMicroelectronics](https://github.com/STMicroelectronics/STM32N6-GettingStarted-ObjectDetection) avec des **tutoriels pas-à-pas**, des **solutions aux problèmes courants** et des **exemples pratiques**, dans un objectif pédagogique et reproductible.

---

## Objectif du projet

Mettre en œuvre une chaîne complète de **détection et de comptage de personnes en temps réel** sur microcontrôleur STM32, en s’appuyant sur :
- une **exécution locale (Edge AI)** sur NPU ;
- un respect strict de la **confidentialité** (aucune image transmise ou stockée) ;
- une approche pédagogique accessible aux étudiants et ingénieurs débutant en IA embarquée.

---

## Contenu du Guide

### 1. [Installation et Configuration](Doc_FR/Guide_Installation.md)
- Installation de **STM32CubeIDE (v1.18.0)** et **STM32CubeProgrammer (v2.18.0)**  
- Configuration de l’environnement de développement  
- FAQ et résolution des erreurs courantes

### 2. [Tutoriel : Détection d’Objets avec IA](Doc_FR/Guide_Detection_Objets.md)
- Comprendre le **NPU du STM32N6 (Neural-ART Accelerator)**  
- Déploiement du modèle **YOLOv10n**  
- Utilisation de **STEdgeAI v2.2.0** pour générer, optimiser et quantifier des modèles IA

### 3. [Programmation Avancée : Boot from Flash](Doc_FR/Guide_Boot_Flash.md)
- Explication des **trois fichiers hexadécimaux essentiels**  
- Procédure de flashage pour un **démarrage autonome depuis la mémoire Flash**

---

## Matériel requis

- **Carte :** STM32N6570-DK (Discovery Kit)  
- **Caméra :** Module caméra IMX335 (fourni avec le kit)  
- **Câble :** USB Type-C  

---

## Structure du dépôt

Ce dépôt contient l’intégralité des ressources nécessaires pour suivre les tutoriels et comprendre le fonctionnement du système :

- `Application/` : code source de l’application de détection  
- `Binary/` : fichiers binaires précompilés prêts à être flashés  
- `Middlewares/` : bibliothèques ST (y compris les composants IA)  
- `Doc_FR/` : **guides et tutoriels détaillés en français**

