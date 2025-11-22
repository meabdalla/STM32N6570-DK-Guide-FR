# Guide d'Installation et Configuration 🛠️

Ce guide couvre l'installation des outils nécessaires pour développer sur STM32N6570-DK.

## 1. Prérequis Logiciels

Pour suivre ce tutoriel, vous devez installer les versions suivantes (ou plus récentes) :

- **STM32CubeIDE v1.17.0** : L'environnement de développement intégré.
- **STM32CubeProgrammer v2.18.0** : Pour flasher la carte.
- **X-CUBE-AI** : Extension pour l'IA (à installer via CubeIDE).

> **Note :** Assurez-vous d'avoir les droits administrateur pour l'installation des pilotes ST-LINK.

## 2. Solutions pour Utilisateurs Mac 🍎

Les outils STM32 (notamment pour le N6) sont principalement optimisés pour Windows/Linux. Si vous êtes sur macOS, voici les solutions recommandées :

### Option A : Machine Virtuelle (Recommandé)
Utilisez **Parallels Desktop** ou **VMware Fusion** pour virtualiser Windows 10/11.
- **Avantage :** Compatibilité totale avec les pilotes USB ST-LINK.
- **Configuration :** Assurez-vous de rediriger les périphériques USB vers la VM.

### Option B : Boot Camp (Mac Intel uniquement)
Installez Windows en natif via Boot Camp. C'est la solution la plus stable pour les Mac à processeur Intel.

### Option C : Docker (Avancé)
Pour la compilation uniquement, vous pouvez utiliser une image Docker contenant la toolchain ARM GCC. Cependant, le flashage restera complexe sans accès direct aux ports USB.

## 3. FAQ et Résolution d'Erreurs ❓

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
