# Guide Complet : Détection d'Objets sur STM32N6570-DK

**Auteur :** Abdalla  
**Contexte :** Projet réalisé au FabLab Valrose (Université Côte d'Azur) dans le cadre du Master 2 ESTEL

Ce dépôt est un guide complet et francophone pour la prise en main du kit de développement **STM32N6570-DK**, avec un focus particulier sur l'**Intelligence Artificielle Embarquée** et la détection de personne.

Il intègre et enrichit le [dépôt officiel de STMicroelectronics](https://github.com/STMicroelectronics/STM32N6-GettingStarted-ObjectDetection) avec des tutoriels pas-à-pas, des solutions aux problèmes courants et des exemples pratiques.

---

## Contenu du Guide

### 1. [Installation et Configuration](Doc_FR/Guide_Installation.md)
- Installation de STM32CubeIDE (v1.18.0) et CubeProgrammer (v2.18.0).
- FAQ et résolution des erreurs courantes.

### 2. [Tutoriel : Détection d'Objets avec IA](Doc_FR/Guide_Detection_Objets.md)
- Comprendre le NPU du STM32N6.
- Déployer le modèle **YOLOv10n** officiel.
- Utiliser **STEdgeAI v2.2.0** pour générer et quantifier vos propres modèles.
- Exemples pratiques avec **TensorFlow Lite**.

### 3. [Programmation Avancée : Boot from Flash](Doc_FR/Guide_Boot_Flash.md)
- Explication des 3 fichiers hexadécimaux essentiels.
- Procédure de flashage pour un démarrage autonome.

---

## Matériel Requis

- **Carte :** STM32N6570-DK (Discovery Kit)
- **Caméra :** Module caméra IMX335 (fourni avec le kit)
- **Câble :** USB Type-C

## Structure du Dépôt

Ce dépôt contient l'intégralité du code source officiel nécessaire pour suivre les tutoriels :

- `Application/` : Code source de l'application de détection.
- `Binary/` : Fichiers binaires pré-compilés prêts à être flashés.
- `Middlewares/` : Bibliothèques ST (y compris l'IA).
- `Doc_FR/` : **Les guides et tutoriels en français.**

---

