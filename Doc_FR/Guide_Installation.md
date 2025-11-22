# Guide d'Installation et Configuration

Ce guide couvre l'installation des outils nécessaires pour développer sur STM32N6570-DK.

## 1. Prérequis Logiciels

Pour suivre ce tutoriel, vous devez installer les versions suivantes :

- **STM32CubeIDE v1.18.0** VERSION OBLIGATOIRE (les versions précédentes ne sont pas compatibles avec le STM32N6).
- **STM32CubeProgrammer v2.18.0** : Pour flasher la carte.
- **X-CUBE-AI** : Extension pour l'IA (à installer via CubeIDE).

> **Note :** Assurez-vous d'avoir les droits administrateur pour l'installation des pilotes ST-LINK.

## 2. FAQ et Résolution d'Erreurs

### Erreur : "ST-LINK not found"
- Vérifiez que le câble USB est bien connecté au port **CN6 (ST-LINK)** et non au port User USB.
- Changez de câble USB (certains câbles ne font que la charge).
- Réinstallez les pilotes ST-LINK.

### Erreur : "Download verification failed"
- Cela arrive souvent si la flash externe n'est pas correctement initialisée.
- Utilisez le fichier `ExternalLoader` fourni dans `bin/ExternalLoader/MX66UW1G45G_STM32N6570-DK.stldr`.

### Erreur de Compilation (Make)
- Assurez-vous que le chemin vers votre projet ne contient pas d'espaces.
- Vérifiez que `arm-none-eabi-gcc` est bien dans votre PATH.
