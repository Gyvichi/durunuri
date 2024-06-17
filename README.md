#Models & Learning methods
cf. -NN(Neural Network)
## 0. Learning(Training)
1. Online
2. Batch
3. Rule-based
4. Transfer
5. Office
6. Supervised
	1. Self-supervised
	2. Semi-supervised
7. Meta
	1. Meta-reinforcement

- Pre-trained
- Fine-tuning

### 0-1. Data
1. Image
	1. Gray-scale : 2D Matrix → 3D Matrix if multiple photos.
	2. Color: 3D Matrix (3 2D Matrix due to RGB.) → 4D Matrix if multiple photos.
## 1. Tasks
1. CV
	1. Image Classification
	2. Image Enhancement
	3. Image Registeration
	4. Image Segmentation
		1. Sementic
		2. Instance
	5. Imagee Thresholding
	6. Image Transform
	7. Image Clustering
	8. Object Detection
	9. Object Recognition
	10. Object Tracking
	11. Pattern Recognition
	12. Stereo Vision
2.  Multimodal Learning(A-to-B)
	- A, B: Image or Text or Video or Speech or etc.
	2. Image-to-Text, Text-to-Image
	3. Text-to-Video, Video-to-Text
	4. Text-to-Speech
3.  Feature Engineering
4.  Density Estimation
5.  Anomaly Detection
	1. k-NN
	2. LOF(Local Outiler Factor)
	3. Isolation Forest
### 1-1. AI, not ML
- Rule-based Algorithm
- Experts system: 특정 분야의 전문가처럼 동작하는 시스템.
 - First experts system: DENDRAL(1960s): 수많은 if else 구문으로 동작

cf. ML은 Data-based이다. Rule-based의 단점은 수많은 데이터들의 공통점을 직접 찾아 그 한계 내에서 규칙을 찾아야 한다는 것인데, Data-based의 경우 직접 공통점을 찾기 때문에 정량적 해석이 불가능한 데이터도 높은 정확도로 처리 가능하게 한다. 
### 1-2. ML Tasks & Methods
1. Supervised
	1. Regression
		1. Linear
		2. Ridge
		3. Lasso
	2. Classification
		1. k-NN(k-Nearest Neighbor)
		2. SVM
		3. NBC
	3. Localization
	4. Object Detection
	5. Pose Estimation
	
2. Unsupervised
	1. Cluster Analysis(군집화)
		1. k-means
		2. DBSCAN(Density-based spatial clustering of applications with noise)
			1. OPTICS(Ordering Points To Identify Cluster Structure)
	2. Dimension Reduction
		1. PCA(Principal Component Analysis)
		2. SVD(Singular Value Decomposition)

### 1-3. ML, not ANN: Data Base
1. NBC(Naive Bayesian Classifier)
2. Decision Tree
3. SVM(Support Vector Machine)
4. Perceptron
5. Ensembles
	1. Boosting
	2. Random Forest

### 1-4. ANN Structure: DNN Base
Mainly FFN(Feed-foward Neural Network) & RNN

1. Perceptron → MLP(Multi Layor Perceptron)
3. CNN(Convolution NN, ConvNet) → U-Net
4. RNN(Recurrent NN) → LSTM(Long-Short Time Memory) → GRU(Gated Recurrent Unit)
5. GNN(Graph NN)
6. GAN(Generative Adversariial Network)
7. RBM(Restricted Boltzmann Machine) $\in$ BM(Boltzmann Machine)  → DBN(Deep Belief Network) & DBM(Deep Boltzmann Machine) → X.
10. Transformer, AutoEncoder → Deep Belief Autoencoder $\in$ Encoder-Decoder
13. Diffusion Model
14. SNN(Spike NN)
	- 인간의 뇌를 모방 → Backpropagation X. 연구 중.
### 1-5. Basic RL Model
1. Q-learning → DQN(Deep Q-Network)
2. MARL(Multi-agent reinforcement learning)

### 1-6. Data Related Task
1. Data Cleaning
2. Data Fitting
3. Data Augmentation
4. Data Visualization
5. Data Preprocessing
### 1-7. NLP Tasks
1. Text Generation
2. Machine Translation
3. Question Asking
4. Context Extraction
5. Sentiment Analysis
6. Topic Modeling

##### 1-8. Automated ML
- AutoML
## 2. CV Models
 **2-1. ImageNet**
 - Visual DB for Object Recognition
 - Established ImageNet(2010)
 - Host ILSRVC
 
 **2-2. SOTA Models on ImageNet DB**
 - ILSRVC Classification Results(CLS)

|                |       | 2014    | 2015   |
| :------------- | ----: | ------- | ------ |
| Model          | Human | VGG-Net | ResNet |
| Algorithm Base |       | CNN     | CNN    |
| Error[%]       |   5.1 | 6.7     | 3.6    |
- Vision Transformer(2020)

**2-3. Object Detection Model**
- Faster R-CNN
- RetinaNet

## 3. NLP
- Switch Transformer
