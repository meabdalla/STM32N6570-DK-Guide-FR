# Tutoriel : Détection d'Objets avec IA Embarquée

Ce tutoriel vous guide pas-à-pas pour déployer un modèle de détection d'objets sur le STM32N6 en utilisant son NPU.

## 1. Comprendre le NPU du STM32N6

Le STM32N6 intègre un **Neural Processing Unit (NPU)** dédié. Contrairement au CPU (Cortex-M55), le NPU est optimisé pour les calculs matriciels lourds requis par les réseaux de neurones (CNN).
- **Performance :** Inférence beaucoup plus rapide.
- **Efficacité :** Consommation d'énergie réduite.
- **Format :** Le NPU travaille idéalement avec des modèles quantifiés en **int8**.

## 2. Déployer le Modèle YOLOv8 Officiel

Le projet est fourni avec un modèle YOLOv8n pré-entraîné et converti.

### Étapes :
1. Ouvrez le projet dans **STM32CubeIDE**.
2. Compilez le projet ("Build").
3. Flashez le binaire généré sur la carte.
4. Connectez la carte à un écran (via USB UVC ou SPI) pour voir les détections.

## 3. Utiliser STEdgeAI v2.2.0

Pour utiliser votre propre modèle, vous devez utiliser **STEdgeAI** (compatible avec STM32CubeIDE v1.18.0).

### Génération et Quantization :
1. **Entraînement :** Entraînez votre modèle YOLOv8 avec Ultralytics (Python). Exportez-le en format `.tflite`.
2. **STEdgeAI Core :** Utilisez l'outil en ligne de commande ou via CubeMX.
   ```bash
   stedgeai generate --target stm32n6 --model votre_modele.tflite --output ./generated_code --quantize
   ```
3. **Intégration :** Copiez les fichiers `.c` et `.h` générés dans le dossier `Middlewares/ST/AI` de votre projet.

## 4. Exemples Pratiques : TensorFlow Lite

Si vous préférez TensorFlow Lite for Microcontrollers :

1. Téléchargez un modèle TFLite (ex: MobileNet SSD).
2. Assurez-vous qu'il est quantifié (int8).
3. Utilisez le script de conversion fourni par ST pour l'adapter au format NPU.
4. Modifiez `app_x-cube-ai.c` pour pointer vers votre nouveau réseau.

> **Astuce :** Commencez toujours par le modèle "toy" fourni pour valider votre chaîne de compilation avant d'essayer votre propre modèle.
