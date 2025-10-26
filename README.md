# 📘 Guide STM32N6570-DK (Français)

Guide complet pour programmer la carte de développement **STM32N6570-DK** de STMicroelectronics avec STM32CubeIDE et STM32CubeProgrammer.

---

## 🚨 AVERTISSEMENT CRITIQUE : WINDOWS UNIQUEMENT (POUR LE MOMENT)

> # ⛔ **UTILISATEURS macOS : CETTE CARTE NE FONCTIONNE PAS SUR macOS** ⛔
>
> ---
>
> # **LA CARTE STM32N6570-DK NE FONCTIONNE QUE SUR WINDOWS**
> # **(POUR LE MOMENT)**
>
> ---
>
> ## ❌ ❌ ❌ **macOS NE FONCTIONNE PAS** ❌ ❌ ❌
>
> - 🚫 La carte **n'est PAS reconnue** sur macOS
> - 🚫 **AUCUNE version** de STM32CubeIDE ne fonctionne sur Mac
> - 🚫 Ni Intel, ni Apple Silicon (M1/M2/M3)
> - 🚫 **Impossible actuellement** - cela pourrait changer dans le futur
>
> ---
>
> ## ✅ ✅ ✅ **WINDOWS 10/11 UNIQUEMENT** ✅ ✅ ✅
>
> - ✔️ **SEUL** Windows fonctionne
> - ✔️ Utilisation complète et fiable garantie
>
> ---
>
> ## 💡 **Solutions pour utilisateurs Mac :**
> - **Machine virtuelle Windows** (Parallels, VMware Fusion, VirtualBox)
> - **Boot Camp** (Mac Intel uniquement)
> - **Accès à un PC Windows**
>
> 👉 Consultez la section [Solutions alternatives pour Mac](#-solutions-alternatives-pour-utilisateurs-mac) pour plus de détails.

---

## 📋 Table des Matières

1. [Introduction à la carte STM32N6570-DK](#-introduction-à-la-carte-stm32n6570-dk)
2. [Prérequis](#-prérequis)
3. [Installation des outils nécessaires](#-installation-des-outils-nécessaires)
   - [STM32CubeProgrammer v2.18.0](#1-stm32cubeprogrammer-v2180)
   - [STM32CubeIDE v1.17.0](#2-stm32cubeide-v1170)
4. [Solutions alternatives pour utilisateurs Mac](#-solutions-alternatives-pour-utilisateurs-mac)
5. [Connexion et programmation avec STM32CubeProgrammer](#-connexion-et-programmation-avec-stm32cubeprogrammer)
6. [Création, compilation et téléversement avec STM32CubeIDE](#-création-compilation-et-téléversement-avec-stm32cubeide)
7. [Liens utiles](#-liens-utiles)
8. [FAQ / Erreurs fréquentes](#-faq--erreurs-fréquentes)

---

## 🎯 Introduction à la carte STM32N6570-DK

La **STM32N6570-DK** est une carte de développement de la famille STM32N6, conçue pour le développement d'applications embarquées hautes performances. Elle est idéale pour l'apprentissage et le prototypage rapide.

### Caractéristiques principales :

- **Microcontrôleur** : STM32N6570 (architecture ARM Cortex-M55)
- **Mémoire** : Flash **externe** (OSPI) et RAM interne 8 MB
- **Connectivité** : USB, Ethernet, interfaces série (UART, SPI, I2C)
- **Débogage intégré** : ST-Link V3 embarqué
- **Affichage** : Écran tactile couleur 480x800 pixels
- **Capteurs et périphériques** : Boutons, LEDs, connecteurs d'extension

### À quoi sert cette carte ?

- Développement d'applications IoT
- Prototypage d'interfaces graphiques embarquées
- Apprentissage de la programmation embarquée sur ARM Cortex-M
- **Exécution de modèles d'IA embarqués** (détection d'objets, reconnaissance d'images)
- Tests et validation de concepts temps réel

### ⚠️ PARTICULARITÉ CRITIQUE DE LA STM32N6

> **🚨 IMPORTANT : La série STM32N6 N'A PAS de mémoire Flash interne !**
>
> Contrairement aux autres STM32, la STM32N6570 **ne possède pas de Flash interne**. Cela signifie :
>
> - ✅ **Mode Development** : Le code peut être chargé temporairement en RAM pour les tests (perdu au redémarrage)
> - ✅ **Mode Boot from Flash** : Le code doit être programmé dans la **Flash externe** pour persister après extinction
> - ❌ Vous **ne pouvez PAS** simplement "uploader" un programme comme sur une STM32F4 ou STM32L4
> - 📋 La programmation nécessite **3 fichiers .hex** : bootloader, données réseau, application
>
> Ce tutoriel vous expliquera les deux modes de fonctionnement.

![Carte STM32N6570-DK](images/stm32n6570-dk-board.jpg)
> *📷 Remplacez cette ligne par votre capture d'écran de la carte*

---

## ✅ Prérequis

Avant de commencer, assurez-vous de disposer des éléments suivants :

### Matériel :
- Une carte **STM32N6570-DK**
- Un câble USB Type-C (pour programmation et alimentation)
- **Un ordinateur sous Windows 10 ou Windows 11** (⚠️ **macOS n'est PAS supporté pour le moment** !)

### Logiciels (Versions spécifiques OBLIGATOIRES) :

⚠️ **ATTENTION : Utilisez UNIQUEMENT ces versions exactes !**

- **STM32CubeIDE v1.17.0** : environnement de développement intégré
- **STM32CubeProgrammer v2.18.0** : pour programmer la carte
- **STEdgeAI v2.2.0** : pour générer des modèles IA (optionnel pour ce tutoriel de base)

❌ **Les autres versions (plus anciennes ou plus récentes) peuvent ne PAS fonctionner correctement avec la STM32N6570-DK !**

### Liens officiels STMicroelectronics :

| Outil | Lien de téléchargement |
|-------|------------------------|
| STM32CubeProgrammer v2.18.0 | [https://www.st.com/en/development-tools/stm32cubeprog.html](https://www.st.com/en/development-tools/stm32cubeprog.html) |
| STM32CubeIDE v1.17.0 | [https://www.st.com/en/development-tools/stm32cubeide.html](https://www.st.com/en/development-tools/stm32cubeide.html) |
| Documentation STM32N6 | [https://www.st.com/en/microcontrollers-microprocessors/stm32n6-series.html](https://www.st.com/en/microcontrollers-microprocessors/stm32n6-series.html) |
| Repository GitHub STM32N6 | [https://github.com/STMicroelectronics/STM32N6-GettingStarted-ObjectDetection](https://github.com/STMicroelectronics/STM32N6-GettingStarted-ObjectDetection) |

---

## 🛠️ Installation des outils nécessaires

### 1. STM32CubeProgrammer v2.18.0

**STM32CubeProgrammer** est l'outil officiel de STMicroelectronics permettant de programmer et d'effacer la mémoire Flash des microcontrôleurs STM32.

⚠️ **Version requise : v2.18.0 UNIQUEMENT** - Les autres versions peuvent causer des problèmes avec la STM32N6570-DK.

#### Étapes d'installation :

1. **Téléchargement** :
   - Rendez-vous sur [cette page](https://www.st.com/en/development-tools/stm32cubeprog.html)
   - Cliquez sur "Get Software"
   - Connectez-vous avec votre compte ST (ou créez-en un gratuitement)
   - Téléchargez la version correspondant à votre système d'exploitation

![Téléchargement STM32CubeProgrammer](images/download-cubeprogrammer.png)
> *📷 Capture d'écran de la page de téléchargement*

2. **Installation (Windows uniquement)** :
   - Exécutez le fichier `.exe` téléchargé
   - Suivez l'assistant d'installation
   - Acceptez les conditions de licence
   - Choisissez le répertoire d'installation (ou laissez par défaut)
   - Attendez la fin de l'installation

3. **Vérification** :
   - Lancez STM32CubeProgrammer
   - L'interface graphique devrait s'ouvrir sans erreur

![Interface STM32CubeProgrammer](images/cubeprogrammer-interface.png)
> *📷 Capture d'écran de l'interface principale*

**💡 Note importante :** Les drivers USB nécessaires sont **automatiquement installés** avec STM32CubeProgrammer et STM32CubeIDE. Aucune installation séparée n'est requise !

---

### 2. STM32CubeIDE v1.17.0

**STM32CubeIDE** est l'environnement de développement intégré officiel de STMicroelectronics, basé sur Eclipse, permettant de créer, compiler et déboguer vos projets STM32.

⚠️ **Version requise : v1.17.0 UNIQUEMENT** - Cette version spécifique est testée et validée pour la STM32N6570-DK.

#### Étapes d'installation :

1. **Téléchargement de la version 1.17.0** :
   - Rendez-vous sur [cette page](https://www.st.com/en/development-tools/stm32cubeide.html)
   - Cliquez sur "Get Software"
   - **Important** : Descendez jusqu'à la section **"Version History"** ou **"All versions"**
   - Recherchez et téléchargez **STM32CubeIDE 1.17.0** pour Windows
   - Si vous ne trouvez pas cette version, elle peut être dans les archives

![Téléchargement STM32CubeIDE](images/download-cubeide.png)
> *📷 Capture d'écran de la page de téléchargement*

2. **Installation (Windows uniquement)** :
   - Exécutez l'installeur `.exe` téléchargé
   - Suivez l'assistant d'installation
   - Acceptez les conditions de licence
   - Choisissez le répertoire d'installation (ou laissez par défaut : `C:\ST\STM32CubeIDE`)
   - Attendez la fin de l'installation (peut prendre plusieurs minutes)
   - Les drivers USB sont installés automatiquement

**⚠️ Note pour utilisateurs Mac :**
L'installation de STM32CubeIDE sur Mac est inutile pour cette carte, car elle ne sera de toute façon pas reconnue **pour le moment**. Utilisez une solution de virtualisation Windows (voir section ci-dessous).

3. **Premier lancement** :
   - Lors du premier démarrage, choisissez un emplacement pour votre workspace (espace de travail)
   - Acceptez les licences si demandé

![Premier lancement STM32CubeIDE](images/cubeide-first-launch.png)
> *📷 Capture d'écran du choix du workspace*

4. **Configuration initiale** :
   - STM32CubeIDE va télécharger les packs nécessaires pour les microcontrôleurs STM32
   - Ce processus peut prendre quelques minutes

![Configuration STM32CubeIDE](images/cubeide-setup.png)
> *📷 Capture d'écran du téléchargement des packs*

---

## 🖥️ Solutions alternatives pour utilisateurs Mac

**Vous utilisez macOS ?** Comme expliqué précédemment, la carte STM32N6570-DK ne fonctionne **QUE sous Windows (pour le moment)**. Voici vos options pour pouvoir quand même l'utiliser :

### Option 1 : Machine virtuelle Windows (Recommandé) 💻

Cette solution permet de faire tourner Windows dans une fenêtre sur votre Mac.

#### Sur macOS :

**Logiciels disponibles :**
- **Parallels Desktop** (payant ~100€/an) - Le plus performant, supporte Apple Silicon
- **VMware Fusion** (gratuit pour usage personnel depuis 2024) - Très bon aussi
- **VirtualBox** (gratuit, open-source) - Correct mais moins performant

**Étapes avec Parallels Desktop (recommandé pour Mac) :**

1. **Achetez et installez Parallels Desktop** depuis [parallels.com](https://www.parallels.com)
2. **Téléchargez Windows 10/11** :
   - Parallels peut télécharger Windows automatiquement
   - Ou téléchargez une ISO depuis [microsoft.com](https://www.microsoft.com/software-download/windows11)
3. **Créez la machine virtuelle** :
   - Lancez Parallels
   - Créez une nouvelle VM
   - Allouez au moins 4 Go de RAM et 2 CPU
   - Installez Windows
4. **Configurez le passage USB** :
   - Branchez la carte STM32N6570-DK
   - Dans Parallels, menu **Devices → USB & Bluetooth → STMicroelectronics STLink**
   - Cochez "Connect to Windows"
5. **Installez les outils** dans Windows :
   - STM32CubeIDE
   - STM32CubeProgrammer
   - Drivers ST-Link
6. **Travaillez normalement** comme si vous étiez sur un PC Windows !

**Étapes avec VirtualBox (gratuit) :**

1. **Installez VirtualBox** depuis [virtualbox.org](https://www.virtualbox.org)
2. **Installez le Extension Pack** (obligatoire pour USB 3.0)
3. **Créez une VM Windows 10/11** :
   - 4 Go RAM minimum (8 Go recommandé)
   - 50 Go d'espace disque
   - Activez le support USB 3.0 dans Settings → USB
4. **Configurez USB** :
   - Settings → USB → Add new USB filter
   - Sélectionnez "STMicroelectronics" quand la carte est branchée
5. **Installez Windows et les outils**

---

### Option 2 : Boot Camp (Mac Intel uniquement) 🍎

Boot Camp permet d'installer Windows en dual-boot sur un Mac Intel (ne fonctionne PAS sur Mac Apple Silicon M1/M2/M3).

**Avantages :**
- Performances natives (pas de virtualisation)
- Accès complet au matériel

**Inconvénients :**
- Nécessite de redémarrer pour changer d'OS
- Prend beaucoup d'espace disque (min 64 Go)

**Étapes :**

1. **Vérifiez que vous avez un Mac Intel** :
   - Menu Pomme → À propos de ce Mac
   - Si vous voyez "Processeur Intel", OK
   - Si vous voyez "Puce Apple M1/M2/M3", Boot Camp n'est pas disponible

2. **Sauvegardez vos données** (Time Machine recommandé)

3. **Téléchargez Windows 10/11 ISO** depuis microsoft.com

4. **Lancez l'Assistant Boot Camp** :
   - Applications → Utilitaires → Assistant Boot Camp
   - Suivez les instructions
   - Allouez au moins 64 Go pour Windows (100 Go recommandé)

5. **Installez Windows** (l'assistant le fait automatiquement)

6. **Installez les drivers Boot Camp** (démarre automatiquement sous Windows)

7. **Installez les outils STM32** sous Windows

8. **Basculer entre macOS et Windows** :
   - Redémarrez et maintenez la touche Option (⌥) au démarrage
   - Choisissez le disque de démarrage

### Option 3 : Accès distant à un PC Windows 🌐

Si vous avez accès à un PC Windows (au travail, chez un ami, etc.) :

1. **Installez un logiciel de bureau à distance** :
   - **TeamViewer** (gratuit pour usage personnel)
   - **Chrome Remote Desktop** (gratuit)
   - **Microsoft Remote Desktop** (si le PC est sous Windows Pro)

2. **Configurez l'accès distant sur le PC Windows**

3. **Connectez-vous depuis votre Mac**

4. **Branchez la carte sur le PC Windows**

5. **Travaillez à distance** (peut être lent selon votre connexion)

### Option 4 : Acheter un mini PC Windows 💰

Solution radicale mais efficace :

- **Mini PC Windows** (200-400€) : Intel NUC, Beelink, etc.
- Branchez-y un écran/clavier/souris ou utilisez-le en headless via Remote Desktop
- Dédiez-le au développement embarqué

### ⚠️ Ce qui NE fonctionne PAS sur macOS :

❌ Installer les drivers manuellement sur Mac
❌ Utiliser Wine ou CrossOver
❌ Compiler des drivers open-source alternatifs
❌ Utiliser d'anciennes versions de STM32CubeIDE
❌ Attendre un miracle 🙏

**La virtualisation Windows est votre meilleure option pour les utilisateurs Mac !**

---

## 🔌 Connexion et programmation avec STM32CubeProgrammer

Cette section explique comment connecter votre carte STM32N6570-DK et programmer la mémoire Flash à l'aide de STM32CubeProgrammer.

### Étape 1 : Connexion physique de la carte

1. **Branchez le câble USB Type-C** sur le connecteur USB de la carte (marqué "USB STLINK" ou "CN15")
2. **Connectez l'autre extrémité** à votre ordinateur Windows
3. **Vérifiez l'alimentation** : une LED verte devrait s'allumer sur la carte

![Connexion USB carte](images/board-usb-connection.jpg)
> *📷 Photo montrant le branchement du câble USB*

💡 **Astuce** : Utilisez un port USB 3.0 (bleu) pour une meilleure alimentation et une connexion plus stable.

### Étape 2 : Connexion dans STM32CubeProgrammer

1. **Lancez STM32CubeProgrammer**
2. Dans le coin supérieur droit, sélectionnez **"ST-LINK"** dans le menu déroulant
3. Cliquez sur le bouton **🔄 Refresh** pour détecter automatiquement la carte
4. Les paramètres devraient être automatiquement détectés :
   - **Port** : USB
   - **Serial Number** : détecté automatiquement
   - **Frequency** : 4000 kHz (par défaut)
   - **Mode** : Under Reset (recommandé)
5. Cliquez sur le bouton vert **"Connect"**

![Connexion STM32CubeProgrammer](images/cubeprogrammer-connect.png)
> *📷 Capture d'écran de la connexion réussie*

### Étape 3 : Vérification de la connexion

Une fois connecté, vous devriez voir :
- Le message **"Connected"** en vert
- Les informations sur le microcontrôleur (Device ID, Flash Size, etc.)
- L'onglet "Memory & file editing" devient actif

![Informations device](images/cubeprogrammer-device-info.png)
> *📷 Capture d'écran des informations du device*

### Étape 4 : Programmation d'un fichier binaire

Pour programmer un fichier `.hex` ou `.bin` sur la carte :

1. Cliquez sur l'onglet **"Erasing & Programming"** dans le menu de gauche
2. Cliquez sur **"Browse"** et sélectionnez votre fichier (`.hex`, `.bin`, `.elf`)
3. Configurez les options :
   - ✅ **Verify programming** (recommandé)
   - ✅ **Run after programming** (si vous voulez exécuter le code immédiatement)
   - ⬜ **Skip flash erase** (décoché pour un effacement complet)
4. Cliquez sur **"Start Programming"**

![Programmation fichier](images/cubeprogrammer-programming.png)
> *📷 Capture d'écran de la programmation en cours*

5. Attendez la fin de l'opération. Un message **"File download complete"** devrait apparaître

![Programmation réussie](images/cubeprogrammer-success.png)
> *📷 Capture d'écran de la programmation réussie*

### Étape 5 : Lecture de la mémoire

Pour lire le contenu actuel de la mémoire Flash :

1. Cliquez sur l'onglet **"Memory & file editing"**
2. Entrez l'adresse de départ (généralement `0x08000000` pour la Flash)
3. Définissez la taille à lire
4. Cliquez sur **"Read"**
5. Le contenu s'affichera en format hexadécimal

![Lecture mémoire](images/cubeprogrammer-read-memory.png)
> *📷 Capture d'écran de la lecture mémoire*

---

## 💻 Création, compilation et téléversement avec STM32CubeIDE

STM32CubeIDE vous permet de créer un projet complet, écrire votre code, le compiler et le téléverser directement sur la carte.

### Étape 1 : Création d'un nouveau projet

1. **Lancez STM32CubeIDE**
2. Cliquez sur **File → New → STM32 Project**

![Nouveau projet](images/cubeide-new-project.png)
> *📷 Capture d'écran du menu*

3. La fenêtre **"Target Selection"** s'ouvre
4. Vous avez deux options :
   - **Board Selector** : recherchez "STM32N6570-DK" pour créer un projet préconfigur é pour votre carte
   - **MCU/MPU Selector** : recherchez "STM32N6570" pour configurer manuellement

![Sélection target](images/cubeide-target-selection.png)
> *📷 Capture d'écran de la sélection de la cible*

5. Sélectionnez votre carte et cliquez sur **"Next"**

### Étape 2 : Configuration du projet

1. Donnez un **nom à votre projet** (ex: "MonPremierProjet_STM32N6")
2. Choisissez la **localisation** du projet (ou laissez par défaut dans votre workspace)
3. Sélectionnez le **langage** :
   - C
   - C++
4. Cliquez sur **"Finish"**

![Configuration projet](images/cubeide-project-config.png)
> *📷 Capture d'écran de la configuration*

5. Si demandé, acceptez l'initialisation avec les **valeurs par défaut**

### Étape 3 : Configuration des périphériques avec STM32CubeMX intégré

STM32CubeIDE ouvre automatiquement l'interface graphique **CubeMX** (fichier `.ioc`) pour configurer les périphériques.

1. **Configurez vos pins** :
   - Cliquez sur un pin dans le schéma pour l'assigner à une fonction (GPIO, UART, etc.)
   - Exemple : Configurer une LED sur un GPIO en Output

![Configuration pins](images/cubeide-pin-config.png)
> *📷 Capture d'écran de la configuration des pins*

2. **Configurez les périphériques** dans les catégories à gauche :
   - System Core (RCC, GPIO, NVIC, etc.)
   - Timers
   - Connectivity (UART, SPI, I2C, USB, etc.)
   - Analog (ADC, DAC)

3. **Configuration de l'horloge** :
   - Allez dans l'onglet **"Clock Configuration"**
   - STM32CubeIDE propose généralement une configuration optimale

![Configuration horloge](images/cubeide-clock-config.png)
> *📷 Capture d'écran de la configuration de l'horloge*

4. **Génération du code** :
   - Cliquez sur le bouton **"Device Configuration Tool Code Generation"** (⚙️) en haut à droite
   - Ou appuyez sur `Ctrl+S` pour sauvegarder et générer le code automatiquement

### Étape 4 : Écriture du code

Le code généré se trouve dans le dossier `Core/Src/main.c`.

1. Ouvrez le fichier **`main.c`**
2. Trouvez la fonction `main()` et la boucle infinie `while(1)`
3. Ajoutez votre code entre les commentaires `/* USER CODE BEGIN */` et `/* USER CODE END */`

**Exemple** : Faire clignoter une LED

```c
/* USER CODE BEGIN WHILE */
while (1)
{
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);  // Inverse l'état de la LED
  HAL_Delay(500);  // Pause de 500 ms
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
}
/* USER CODE END 3 */
```

![Édition code](images/cubeide-code-edit.png)
> *📷 Capture d'écran de l'édition du code*

### Étape 5 : Compilation du projet

1. Cliquez sur le bouton **"Build"** (🔨) dans la barre d'outils
   - Ou appuyez sur `Ctrl+B`
   - Ou cliquez sur **Project → Build Project**

![Compilation](images/cubeide-build.png)
> *📷 Capture d'écran du bouton Build*

2. La console affiche la progression de la compilation
3. Si tout se passe bien, vous verrez le message **"Build Finished. 0 errors, X warnings"**

![Compilation réussie](images/cubeide-build-success.png)
> *📷 Capture d'écran de la compilation réussie*

4. Le fichier compilé (`.elf`) est généré dans le dossier **`Debug/`** ou **`Release/`**

### Étape 6 : Configuration du débogueur (première fois)

Si c'est votre premier téléversement :

1. Cliquez sur **Run → Debug Configurations...**
2. Double-cliquez sur **"STM32 Cortex-M C/C++ Application"**
3. Une nouvelle configuration est créée automatiquement
4. Dans l'onglet **"Debugger"** :
   - Debug probe : ST-LINK (ST-LINK GDB server)
   - Interface : SWD
   - Frequency : 4000 kHz

![Configuration debug](images/cubeide-debug-config.png)
> *📷 Capture d'écran de la configuration du debugger*

5. Cliquez sur **"Apply"** puis **"Close"**

### Étape 7 : Téléversement et exécution

1. **Branchez votre carte** via USB si ce n'est pas déjà fait
2. Cliquez sur le bouton **"Run"** (▶️) ou **"Debug"** (🐞) dans la barre d'outils
   - **Run** : Téléverse et exécute le programme sans s'arrêter
   - **Debug** : Téléverse et lance le mode débogage

![Téléversement](images/cubeide-run-debug.png)
> *📷 Capture d'écran des boutons Run et Debug*

3. STM32CubeIDE va :
   - Compiler le projet (si nécessaire)
   - Se connecter à la carte via ST-Link
   - Effacer la Flash
   - Téléverser le programme
   - Démarrer l'exécution

4. La console affiche :
   ```
   Download in Progress:
   File download complete
   Verifying ...
   Download verified successfully
   ```

![Téléversement réussi](images/cubeide-upload-success.png)
> *📷 Capture d'écran du téléversement réussi*

5. **Votre programme s'exécute maintenant sur la carte !**

### Étape 8 : Débogage (optionnel)

En mode Debug, vous pouvez :

- **Poser des breakpoints** : Cliquez dans la marge gauche de l'éditeur
- **Exécuter pas à pas** : Utilisez les boutons Step Over (F6), Step Into (F5), Step Return (F7)
- **Inspecter les variables** : Regardez l'onglet "Variables" pour voir les valeurs en temps réel
- **Voir les registres** : Onglet "Registers"

![Mode débogage](images/cubeide-debugging.png)
> *📷 Capture d'écran du mode débogage*

Pour reprendre l'exécution normale, cliquez sur **"Resume"** (▶️) ou appuyez sur `F8`.

---

## 🔗 Liens utiles

### Repository GitHub officiel STM32N6 :

- **[STM32N6-GettingStarted-ObjectDetection](https://github.com/STMicroelectronics/STM32N6-GettingStarted-ObjectDetection)** - Exemple complet de détection d'objets avec IA embarquée
  - Exemples de code source
  - Fichiers .hex pré-compilés
  - Documentation sur la programmation en mode Boot from Flash
  - Tutoriel d'intégration avec STEdgeAI ModelZoo

### Documentation officielle STMicroelectronics :

- [Page produit STM32N6570-DK](https://www.st.com/en/evaluation-tools/stm32n6570-dk.html)
- [Manuel utilisateur de la carte](https://www.st.com/resource/en/user_manual/um3298-discovery-kit-with-stm32n6570-mcu-stmicroelectronics.pdf)
- [Guide de démarrage rapide STM32N6](https://www.st.com/resource/en/user_manual/um3301-getting-started-with-the-stm32n6-discovery-kit-stmicroelectronics.pdf)
- [Documentation HAL pour STM32N6](https://www.st.com/resource/en/user_manual/um3300-description-of-stm32n6-hal-and-lowlayer-drivers-stmicroelectronics.pdf)
- [STM32CubeIDE - Guide utilisateur](https://www.st.com/resource/en/user_manual/um2609-stm32cubeide-user-guide-stmicroelectronics.pdf)
- [STM32CubeProgrammer - Guide utilisateur](https://www.st.com/resource/en/user_manual/um2237-stm32cubeprogrammer-software-description-stmicroelectronics.pdf)

### Communauté et support :

- [Forum ST Community](https://community.st.com/)
- [Chaîne YouTube STMicroelectronics](https://www.youtube.com/user/STMicroelectronics)
- [Wiki STM32](https://wiki.st.com/stm32mcu/wiki/Main_Page)

### Ressources d'apprentissage :

- [Cours STM32 (français)](https://www.youtube.com/results?search_query=tutoriel+stm32+français)
- [GitHub - Exemples STM32](https://github.com/STMicroelectronics)
- [Awesome STM32 - Liste de ressources](https://github.com/taburyak/awesome-stm32)

---

## ❓ FAQ / Erreurs fréquentes

### ⚠️ QUESTION CRITIQUE : La carte ne fonctionne pas sur macOS

**Symptômes :**
- La carte STM32N6570-DK n'est pas détectée sur macOS
- Erreurs "No ST-LINK detected" dans STM32CubeIDE
- Impossible de se connecter
- Échec de programmation systématique
- Le debugger ne démarre jamais

**Cause :**
❌ **Vous utilisez macOS, qui n'est PAS compatible avec cette carte (pour le moment) !**

**Réalité technique :**
La carte STM32N6570-DK **ne fonctionne correctement QUE sous Windows pour le moment**. STMicroelectronics n'a pas développé de support stable pour macOS pour cette carte spécifique. Cela pourrait évoluer dans le futur.

**SOLUTIONS OBLIGATOIRES pour utilisateurs Mac :**

#### Option 1 : Machine virtuelle Windows (RECOMMANDÉ)

**Sur Mac (Intel ou Apple Silicon avec Rosetta) :**
1. Installez **Parallels Desktop** (payant mais performant) ou **VMware Fusion** ou **VirtualBox** (gratuit)
2. Créez une machine virtuelle Windows 10 ou 11
3. Installez Windows normalement dans la VM
4. **Important** : Configurez le passage USB vers la VM :
   - Dans Parallels : Devices → USB → STMicroelectronics STLink
   - Dans VMware : VM → Removable Devices → STMicroelectronics → Connect
5. Installez STM32CubeIDE et STM32CubeProgrammer dans Windows
6. La carte devrait être détectée

#### Option 2 : Boot Camp (Mac Intel uniquement)

1. Utilisez l'assistant Boot Camp pour partitionner votre disque
2. Installez Windows 10/11 en dual boot
3. Redémarrez sur Windows
4. Installez STM32CubeIDE et les drivers
5. Travaillez nativement sous Windows

#### Option 3 : PC Windows physique

Solution la plus simple : utilisez un PC Windows physique si vous en avez accès.

**⚠️ AUCUNE autre solution ne fonctionne - N'essayez pas de forcer la compatibilité !**

---

### 1. La carte n'est pas détectée par STM32CubeProgrammer (Windows)

**Causes possibles :**
- Câble USB défectueux ou câble de charge uniquement (sans données)
- Port USB sans alimentation suffisante
- Mauvais mode de connexion sélectionné
- Carte non alimentée correctement

**Solutions :**
1. **Vérifiez le câble USB** : Utilisez un câble USB-C de qualité avec support données (pas juste un câble de charge)
2. **Changez de port USB** : Essayez un port USB 3.0 (bleu) pour une meilleure alimentation
3. **Vérifiez l'alimentation** : La LED verte doit être allumée sur la carte
4. **Changez le mode de connexion** dans STM32CubeProgrammer :
   - Essayez "Under Reset" au lieu de "Hot Plug", ou inversement
5. **Redémarrez** STM32CubeProgrammer et reconnectez la carte
6. **Redémarrez Windows** si le problème persiste

---

### 2. Erreur "No target connected" dans STM32CubeIDE

**Solutions :**
1. **Vérifiez la connexion** : Assurez-vous que la carte est branchée et alimentée (LED verte allumée)
2. **Fermez STM32CubeProgrammer** s'il est ouvert (les deux outils ne peuvent pas accéder à la carte en même temps)
3. **Vérifiez la configuration de debug** dans STM32CubeIDE :
   - Menu : Run → Debug Configurations
   - Vérifiez que "ST-LINK (ST-LINK GDB server)" est sélectionné
   - Cliquez sur "Scan" pour détecter la carte
4. **Redémarrez la carte** : Débranchez et rebranchez le câble USB
5. **Redémarrez STM32CubeIDE**

---

### 3. Erreur de compilation "undefined reference to..."

**Cause :**
- Fichiers source manquants ou mal liés

**Solutions :**
1. Vérifiez que tous les fichiers `.c` sont bien inclus dans le projet
2. Faites un clic droit sur le projet → Properties → C/C++ Build → Settings
3. Vérifiez les chemins d'include et les sources
4. Nettoyez et recompilez : Project → Clean... → Clean

---

### 4. Le programme ne s'exécute pas après téléversement

**Causes possibles :**
- Option "Run after programming" désactivée
- Code bloqué dans une fonction d'initialisation
- Problème de configuration d'horloge

**Solutions :**
1. Dans STM32CubeProgrammer, activez "Run after programming"
2. Appuyez sur le bouton RESET de la carte
3. En mode Debug, vérifiez où le code se bloque
4. Revérifiez la configuration de l'horloge dans CubeMX

---

### 5. Warnings "implicit declaration of function..."

**Cause :**
- Fichiers d'en-tête (`.h`) manquants

**Solution :**
1. Ajoutez l'include approprié en haut du fichier `.c` :
   ```c
   #include "stm32n6xx_hal.h"
   ```
2. Vérifiez les chemins d'include dans les propriétés du projet

---

### 6. La carte chauffe anormalement

**Causes possibles :**
- Court-circuit sur les pins
- Consommation excessive d'un périphérique externe

**Solutions :**
1. Débranchez immédiatement la carte
2. Vérifiez les connexions sur les pins d'extension
3. Ne dépassez pas les limites de courant des GPIO (généralement 25 mA par pin)
4. Si le problème persiste, contactez le support ST

---

### 7. Impossible de télécharger avec STM32CubeProgrammer (Error: Data read failed)

**Solutions :**
1. **Effacez complètement la Flash externe** :
   - Dans STM32CubeProgrammer, onglet "Erasing & Programming"
   - Cliquez sur "Full chip erase"
   - Attendez la fin de l'opération
2. **Réduisez la fréquence de connexion** :
   - Dans les paramètres de connexion, changez la fréquence de 4000 kHz à 1000 kHz ou moins
   - Reconnectez-vous à la carte
3. **Changez le mode de connexion** :
   - Essayez "Under Reset" pour forcer la réinitialisation lors de la connexion
4. **Vérifiez la qualité du câble USB** et utilisez un port USB 3.0 si possible

---

### 8. Erreur "Clock configuration issue" dans CubeMX

**Solution :**
1. Dans l'onglet "Clock Configuration" de CubeMX
2. Cliquez sur le bouton "Resolve Clock Issues" (horloge avec ✓)
3. CubeMX proposera automatiquement une configuration valide
4. Régénérez le code

---

### 9. Espace de stockage Flash insuffisant

**Causes :**
- Code trop volumineux
- Optimisation désactivée

**Solutions :**
1. Activez l'optimisation du compilateur :
   - Projet → Properties → C/C++ Build → Settings
   - Optimization : -Os (Optimize for size)
2. Retirez le code et les bibliothèques non utilisés
3. Passez en configuration Release au lieu de Debug

---

### 10. Problèmes de printf / débug via UART

**Pour activer printf via ST-Link :**

1. Ajoutez ces lignes dans `main.c` (avant la fonction main) :
   ```c
   #ifdef __GNUC__
   #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
   #else
   #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
   #endif

   PUTCHAR_PROTOTYPE
   {
     HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
     return ch;
   }
   ```
2. Configurez l'UART3 dans CubeMX (souvent lié au ST-Link Virtual COM Port)
3. Dans STM32CubeIDE, ouvrez la vue "Console SWV" pour voir les messages

---

## 🎉 Conclusion

Vous avez maintenant toutes les clés en main pour développer vos projets sur la carte **STM32N6570-DK** ! Ce tutoriel vous a guidé à travers :

- L'installation complète de l'environnement de développement
- La programmation directe avec STM32CubeProgrammer
- La création, compilation et téléversement de code avec STM32CubeIDE

N'hésitez pas à explorer les exemples fournis par STMicroelectronics, à consulter la documentation et à participer aux forums pour progresser rapidement.

**Bon développement ! 🚀**

---

## 📝 Licence

Ce tutoriel est fourni à titre éducatif. Les marques STM32, STMicroelectronics et logos associés sont la propriété de STMicroelectronics.

---

## 🤝 Contributions

Les contributions pour améliorer ce tutoriel sont les bienvenues ! N'hésitez pas à ouvrir une issue ou une pull request.

---

**Auteur** : [Votre nom]
**Date** : 2025
**Version** : 1.0
