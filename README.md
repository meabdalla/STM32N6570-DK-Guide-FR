# Démarrage Rapide : Détection d'Objets sur STM32N6

Ce projet fournit un environnement temps réel pour les microcontrôleurs **STM32N6** afin d'exécuter des modèles générés par [STEdgeAI](https://www.st.com/en/development-tools/stedgeai-core.html), ciblant spécifiquement la détection d'objets. Le code privilégie la clarté pour servir de point de départ idéal.

![Exemple](_htmresc/sample.PNG)
*Les classes détectées et le niveau de confiance sont affichés sur les cadres.*

Ce projet autonome peut être déployé directement sur le matériel. Il est également intégré au [ST ModelZoo](https://github.com/STMicroelectronics/stm32ai-modelzoo-services).

---

## Table des Matières

- [Fonctionnalités](#fonctionnalités)
- [Matériel Supporté](#matériel-supporté)
- [Versions des Outils](#versions-des-outils)
- [Modes de Démarrage](#modes-de-démarrage)
- [Démarrage Rapide avec Binaires](#démarrage-rapide-avec-binaires)
- [Démarrage Rapide avec Code Source](#démarrage-rapide-avec-code-source)

---

## Fonctionnalités

- Flux d'application séquentiel
- Inférence de modèle IA quantifié accélérée par NPU
- Double pipeline DCMIPP
- Recadrage, décimation et mise à l'échelle DCMIPP
- Utilisation de l'ISP DCMIPP
- Implémentation double couche LTDC
- Mode développement
- Démarrage depuis la flash externe

---

## Matériel Supporté

Plateformes de développement supportées :

- **[STM32N6570-DK](https://www.st.com/en/evaluation-tools/stm32n6570-dk.html) Discovery Board**
  - Connectez le port ST-LINK (CN6) avec un câble **USB-C vers USB-C**.
- **[NUCLEO-N657X0-Q](https://www.st.com/en/evaluation-tools/nucleo-n657x0-q.html) Nucleo Board**
  - Connectez le port ST-LINK (CN9) avec un câble **USB-C vers USB-C**.

![Carte](_htmresc/STM32N6570-DK.png)
*Carte STM32N6570-DK avec caméra IMX335.*

Modules caméra supportés :
- Module caméra IMX335 fourni
- [STEVAL-55G1MBI](https://www.st.com/en/evaluation-tools/steval-55g1mbi.html)
- [STEVAL-66GYMAI1](https://www.st.com/en/evaluation-tools/steval-66gymai.html)

---

## Versions des Outils

- **[STM32CubeIDE](https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-ides/stm32cubeide.html)** (v1.17.0)
- **[STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)** (v2.18.0)
- **[STEdgeAI](https://www.st.com/en/development-tools/stedgeai-core.html)** (v2.2.0)

---

## Modes de Démarrage

Le STM32N6 n'a pas de flash interne. Pour conserver le firmware après redémarrage, il faut le programmer dans la flash externe.

- **Mode Développement :** Chargement en RAM (perdu au redémarrage).
- **Boot from Flash :** Démarrage depuis la flash externe.

| | STM32N6570-DK | NUCLEO-N657X0-Q |
|---|---|---|
| **Boot from flash** | ![Boot from flash](_htmresc/STM32N6570-DK_Boot_from_flash.png) | ![Boot from flash](_htmresc/NUCLEO-N657X0-Q_Boot_from_flash.png) |
| **Mode Développement** | ![Dev mode](_htmresc/STM32N6570-DK_Dev_mode.png) | ![Dev mode](_htmresc/NUCLEO-N657X0-Q_Dev_mode.png) |

---

## Démarrage Rapide avec Binaires

### STM32N6570-DK

1. Mettez la carte en **[mode développement](#modes-de-démarrage)**.
2. Programmez `Binary/ai_fsbl.hex` (Bootloader).
3. Programmez `Binary/STM32N6570-DK_network_data.hex` (Poids du modèle).
4. Programmez `Binary/STM32N6570-DK_GettingStarted_ObjectDetection.hex` (Application).
5. Mettez la carte en **[mode Boot from Flash](#modes-de-démarrage)**.
6. Redémarrez la carte.

### Programmation via Ligne de Commande (Windows)

Assurez-vous que le dossier `bin` de STM32CubeProgrammer est dans votre PATH.

```powershell
set DKEL="<Dossier_Install_STM32CubeProgrammer_N6>/bin/ExternalLoader/MX66UW1G45G_STM32N6570-DK.stldr"

# Bootloader
STM32_Programmer_CLI -c port=SWD mode=HOTPLUG -el %DKEL% -hardRst -w Binary/ai_fsbl.hex

# Poids du modèle
STM32_Programmer_CLI -c port=SWD mode=HOTPLUG -el %DKEL% -hardRst -w Binary/STM32N6570-DK_network_data.hex

# Application
STM32_Programmer_CLI -c port=SWD mode=HOTPLUG -el %DKEL% -hardRst -w Binary/STM32N6570-DK_GettingStarted_ObjectDetection.hex
```

---

## Démarrage Rapide avec Code Source

### STM32CubeIDE

1. Ouvrez le projet via `Application/<nom_carte>/STM32CubeIDE/.project`.
2. Compilez et exécutez le projet.

### Makefile

Naviguez vers `Application/<nom_carte>/` et lancez :

1. Compiler :
    ```bash
    make -j8
    ```
2. Lancer GDB Server :
    ```bash
    ST-LINK_gdbserver -p 61234 -l 1 -d -s -cp <path-to-stm32cubeprogramer-bin-dir> -m 1 -g
    ```
3. Charger le firmware (dans un autre terminal) :
    ```bash
    arm-none-eabi-gdb build/Application/<nom_carte>/Project.elf
    (gdb) target remote :61234
    (gdb) monitor reset
    (gdb) load
    (gdb) continue
    ```
