# Programmation Avancée : Boot from Flash

Le STM32N6 ne possédant pas de flash interne pour le code utilisateur, il est crucial de comprendre comment programmer la flash externe pour un déploiement autonome.

## 1. Les 3 Fichiers Hexadécimaux Essentiels

Pour que votre application fonctionne en mode "Boot from Flash", vous devez flasher **3 fichiers distincts** dans l'ordre :

1.  **`ai_fsbl.hex` (First Stage Boot Loader)**
    *   **Rôle :** C'est le tout premier programme qui s'exécute. Il initialise la mémoire RAM et la flash externe, puis charge l'application principale.
    *   **Sans lui :** La carte ne démarrera jamais.

2.  **`STM32N6570-DK_network_data.hex` (Données du Réseau)**
    *   **Rôle :** Contient les poids et les biais de votre réseau de neurones (le "cerveau" de l'IA).
    *   **Pourquoi séparé ?** Ces données sont volumineuses. Les séparer permet de mettre à jour le code de l'application sans avoir à reflasher tout le modèle IA à chaque fois.

3.  **`STM32N6570-DK_GettingStarted_ObjectDetection.hex` (L'Application)**
    *   **Rôle :** Votre code C compilé (logique métier, gestion caméra, affichage).

## 2. Procédure de Flashage (Pas-à-Pas)

Utilisez **STM32CubeProgrammer** (GUI ou CLI).

### Étape 1 : Mode Développement
Mettez les switchs de la carte en position **Development Mode** (voir schéma sur le PCB).

### Étape 2 : Flasher les fichiers
Flashez les 3 fichiers un par un à leurs adresses respectives (gérées automatiquement par le .hex).

**Commande CLI (Windows) :**
```powershell
set EL="bin/ExternalLoader/MX66UW1G45G_STM32N6570-DK.stldr"

# 1. Bootloader
STM32_Programmer_CLI -c port=SWD -el %EL% -w Binary/ai_fsbl.hex

# 2. Données IA
STM32_Programmer_CLI -c port=SWD -el %EL% -w Binary/STM32N6570-DK_network_data.hex

# 3. Application
STM32_Programmer_CLI -c port=SWD -el %EL% -w Binary/STM32N6570-DK_GettingStarted_ObjectDetection.hex
```

### Étape 3 : Mode Boot
1. Mettez les switchs en position **Boot from Flash**.
2. Appuyez sur le bouton **Reset**.
3. La carte doit démarrer de manière autonome !
