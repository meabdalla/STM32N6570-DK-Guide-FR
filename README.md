# 📘 Tutoriel Complet : Programmation de la Carte STM32N6570-DK

Bienvenue dans ce guide complet pour bien démarrer avec la carte de développement **STM32N6570-DK** de STMicroelectronics. Ce tutoriel vous accompagnera pas à pas, de l'installation des outils jusqu'au téléversement de votre premier programme.

---

## 📋 Table des Matières

1. [Introduction à la carte STM32N6570-DK](#-introduction-à-la-carte-stm32n6570-dk)
2. [Prérequis](#-prérequis)
3. [Installation des outils nécessaires](#-installation-des-outils-nécessaires)
   - [STM32CubeProgrammer](#1-stm32cubeprogrammer)
   - [Drivers ST-Link](#2-drivers-st-link)
   - [STM32CubeIDE](#3-stm32cubeide)
4. [Connexion et programmation avec STM32CubeProgrammer](#-connexion-et-programmation-avec-stm32cubeprogrammer)
5. [Création, compilation et téléversement avec STM32CubeIDE](#-création-compilation-et-téléversement-avec-stm32cubeide)
6. [Liens utiles](#-liens-utiles)
7. [FAQ / Erreurs fréquentes](#-faq--erreurs-fréquentes)

---

## 🎯 Introduction à la carte STM32N6570-DK

La **STM32N6570-DK** est une carte de développement de la famille STM32N6, conçue pour le développement d'applications embarquées hautes performances. Elle est idéale pour l'apprentissage et le prototypage rapide.

### Caractéristiques principales :

- **Microcontrôleur** : STM32N6570 (architecture ARM Cortex-M55)
- **Mémoire** : Flash intégrée et RAM étendue
- **Connectivité** : USB, Ethernet, interfaces série (UART, SPI, I2C)
- **Débogage intégré** : ST-Link V3 embarqué
- **Affichage** : Écran tactile couleur (selon modèle)
- **Capteurs et périphériques** : Boutons, LEDs, connecteurs d'extension

### À quoi sert cette carte ?

- Développement d'applications IoT
- Prototypage d'interfaces graphiques embarquées
- Apprentissage de la programmation embarquée sur ARM Cortex-M
- Tests et validation de concepts temps réel

![Carte STM32N6570-DK](images/stm32n6570-dk-board.jpg)
> *📷 Remplacez cette ligne par votre capture d'écran de la carte*

---

## ✅ Prérequis

Avant de commencer, assurez-vous de disposer des éléments suivants :

### Matériel :
- Une carte **STM32N6570-DK**
- Un câble USB Type-C (pour connexion ST-Link et alimentation)
- Un ordinateur sous Windows, Linux ou macOS

### Logiciels :
- **STM32CubeProgrammer** : pour programmer directement la carte
- **STM32CubeIDE** : environnement de développement intégré
- **Drivers ST-Link** : pour la communication avec la carte

### Liens officiels STMicroelectronics :

| Outil | Lien de téléchargement |
|-------|------------------------|
| STM32CubeProgrammer | [https://www.st.com/en/development-tools/stm32cubeprog.html](https://www.st.com/en/development-tools/stm32cubeprog.html) |
| STM32CubeIDE | [https://www.st.com/en/development-tools/stm32cubeide.html](https://www.st.com/en/development-tools/stm32cubeide.html) |
| Drivers ST-Link | [https://www.st.com/en/development-tools/stsw-link009.html](https://www.st.com/en/development-tools/stsw-link009.html) |
| Documentation STM32N6 | [https://www.st.com/en/microcontrollers-microprocessors/stm32n6-series.html](https://www.st.com/en/microcontrollers-microprocessors/stm32n6-series.html) |

---

## 🛠️ Installation des outils nécessaires

### 1. STM32CubeProgrammer

**STM32CubeProgrammer** est l'outil officiel de STMicroelectronics permettant de programmer et d'effacer la mémoire Flash des microcontrôleurs STM32.

#### Étapes d'installation :

1. **Téléchargement** :
   - Rendez-vous sur [cette page](https://www.st.com/en/development-tools/stm32cubeprog.html)
   - Cliquez sur "Get Software"
   - Connectez-vous avec votre compte ST (ou créez-en un gratuitement)
   - Téléchargez la version correspondant à votre système d'exploitation

![Téléchargement STM32CubeProgrammer](images/download-cubeprogrammer.png)
> *📷 Capture d'écran de la page de téléchargement*

2. **Installation** :
   - **Windows** : Exécutez le fichier `.exe` et suivez l'assistant d'installation
   - **Linux** : Décompressez l'archive et exécutez le script `SetupSTM32CubeProgrammer.sh`
   - **macOS** : Ouvrez le fichier `.dmg` et glissez l'application dans le dossier Applications

3. **Vérification** :
   - Lancez STM32CubeProgrammer
   - L'interface graphique devrait s'ouvrir sans erreur

![Interface STM32CubeProgrammer](images/cubeprogrammer-interface.png)
> *📷 Capture d'écran de l'interface principale*

---

### 2. Drivers ST-Link

Les drivers ST-Link sont essentiels pour établir la communication entre votre ordinateur et la carte via l'interface de débogage ST-Link intégrée.

#### Installation Windows :

1. Téléchargez le package depuis [ce lien](https://www.st.com/en/development-tools/stsw-link009.html)
2. Décompressez l'archive
3. Exécutez `stlink_winusb_install.bat` en tant qu'administrateur
4. Suivez les instructions à l'écran

![Installation drivers ST-Link](images/stlink-driver-install.png)
> *📷 Capture d'écran de l'installation des drivers*

#### Installation Linux :

Les drivers sont généralement inclus dans le noyau Linux moderne. Si nécessaire :

```bash
sudo apt-get update
sudo apt-get install libusb-1.0-0-dev
```

Ajoutez les règles udev :

```bash
sudo cp 49-stlinkv3.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger
```

#### Installation macOS :

Les drivers sont inclus dans STM32CubeProgrammer et STM32CubeIDE.

---

### 3. STM32CubeIDE

**STM32CubeIDE** est l'environnement de développement intégré officiel de STMicroelectronics, basé sur Eclipse, permettant de créer, compiler et déboguer vos projets STM32.

#### Étapes d'installation :

1. **Téléchargement** :
   - Rendez-vous sur [cette page](https://www.st.com/en/development-tools/stm32cubeide.html)
   - Téléchargez la version pour votre système d'exploitation

![Téléchargement STM32CubeIDE](images/download-cubeide.png)
> *📷 Capture d'écran de la page de téléchargement*

2. **Installation** :
   - **Windows** : Exécutez l'installeur `.exe`
   - **Linux** : Exécutez le script d'installation `.sh`
   - **macOS** : Montez le fichier `.dmg` et suivez les instructions

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

## 🔌 Connexion et programmation avec STM32CubeProgrammer

Cette section explique comment connecter votre carte STM32N6570-DK et programmer la mémoire Flash à l'aide de STM32CubeProgrammer.

### Étape 1 : Connexion physique de la carte

1. **Branchez le câble USB Type-C** sur le connecteur ST-Link de la carte (généralement identifié "ST-LINK" ou "USB ST-LINK")
2. **Connectez l'autre extrémité** à votre ordinateur
3. **Vérifiez l'alimentation** : une LED devrait s'allumer sur la carte, indiquant qu'elle est alimentée

![Connexion USB carte](images/board-usb-connection.jpg)
> *📷 Photo montrant le branchement du câble USB*

### Étape 2 : Connexion dans STM32CubeProgrammer

1. **Lancez STM32CubeProgrammer**
2. Dans le coin supérieur droit, sélectionnez **"ST-LINK"** comme méthode de connexion
3. Cliquez sur le bouton **"Refresh"** (🔄) pour détecter automatiquement la carte
4. Les paramètres devraient être automatiquement remplis :
   - **Port** : USB
   - **Serial Number** : Le numéro de série de votre ST-Link
   - **Frequency** : 4000 kHz (par défaut)
   - **Mode** : Under Reset ou Hot Plug
5. Cliquez sur le bouton **"Connect"** (🔌)

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

### 1. La carte n'est pas détectée par STM32CubeProgrammer

**Causes possibles :**
- Drivers ST-Link non installés ou corrompus
- Câble USB défectueux
- Port USB sans alimentation suffisante
- Mauvais mode de connexion sélectionné

**Solutions :**
1. Réinstallez les drivers ST-Link
2. Essayez un autre câble USB ou un autre port USB
3. Dans STM32CubeProgrammer, changez le mode de connexion :
   - Essayez "Under Reset" au lieu de "Hot Plug"
   - Ou inversement
4. Vérifiez que la carte est bien alimentée (LED allumée)
5. Sur Linux, vérifiez les permissions USB :
   ```bash
   sudo usermod -a -G dialout $USER
   sudo usermod -a -G plugdev $USER
   ```
   Puis redémarrez votre session.

---

### 2. Erreur "No target connected" dans STM32CubeIDE

**Solutions :**
1. Assurez-vous que la carte est connectée et alimentée
2. Fermez STM32CubeProgrammer s'il est ouvert (conflit d'accès)
3. Dans STM32CubeIDE :
   - Run → Debug Configurations
   - Vérifiez que ST-LINK est sélectionné
   - Cliquez sur "Scan" pour détecter la carte
4. Redémarrez la carte (débranchez/rebranchez le USB)

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
1. Effectuez un effacement complet de la Flash :
   - Dans STM32CubeProgrammer, onglet "Erasing & Programming"
   - Cliquez sur "Full chip erase"
2. Essayez de réduire la fréquence de connexion :
   - Passez de 4000 kHz à 1000 kHz ou moins
3. Mettez à jour le firmware du ST-Link :
   - Dans STM32CubeProgrammer, menu "Firmware upgrade"
   - Suivez les instructions

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
