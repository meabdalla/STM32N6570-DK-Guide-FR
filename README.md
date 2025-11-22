# Détection d'Objets sur STM32N6570-DK (YOLO)

## 📄 Introduction
Ce dépôt contient le code source complet pour déployer une application de **détection d'objets (YOLO)** sur le kit **STM32N6570-DK**.
Il utilise le **NPU (Neural Processing Unit)** du STM32N6 pour une inférence IA rapide et efficace.

> **Note :** Ce projet est une version francisée et simplifiée du [dépôt officiel STMicroelectronics](https://github.com/STMicroelectronics/STM32N6-GettingStarted-ObjectDetection).

## 🛠️ Matériel Requis
- **Carte :** STM32N6570-DK
- **Caméra :** Module compatible (ex: B-CAMS-OMV, fourni avec le kit)
- **Câble :** USB Type-C (alimentation + data)

## 🚀 Installation Rapide

### 1. Prérequis
- **STM32CubeIDE** (v1.16+)
- **STM32CubeProgrammer**
- **X-CUBE-AI** (Pack d'extension)

### 2. Récupérer le Code
```bash
git clone https://github.com/meabdalla/STM32N6570-DK-Guide-FR.git
```

### 3. Flasher les Binaires Pré-compilés (Méthode la plus simple)
Les binaires se trouvent dans le dossier `Binary/`.
Utilisez **STM32CubeProgrammer** pour flasher les fichiers suivants :
1. `ai_fsbl.hex` (Bootloader)
2. `STM32N6570-DK_network_data.hex` (Poids du modèle IA)
3. `STM32N6570-DK_GettingStarted_ObjectDetection.hex` (Application)

### 4. Compiler depuis les Sources
1. Ouvrez **STM32CubeIDE**.
2. Importez le projet : `File > Import > Existing Projects into Workspace`.
3. Sélectionnez le dossier `Application/STM32N6570-DK/STM32CubeIDE`.
4. Compilez et débuggez ("Run").

## 🧠 Modifier le Modèle IA
Le projet utilise un modèle YOLOv8n quantifié. Pour utiliser votre propre modèle :
1. Entraînez votre modèle YOLO.
2. Convertissez-le en **TFLite (int8)**.
3. Utilisez **STM32Cube.AI** pour générer le code C.
4. Remplacez les fichiers dans `Middlewares/ST/AI`.

## 📂 Structure des Dossiers
- `Application/` : Code source spécifique à la carte.
- `Binary/` : Fichiers .hex prêts à l'emploi.
- `Common/` : Code partagé (Drivers, Utilitaires).
- `Middlewares/` : Bibliothèques ST (IA, HAL, etc.).
