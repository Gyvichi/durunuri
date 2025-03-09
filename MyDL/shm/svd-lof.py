from sklearn.neighbors import LocalOutlierFactor
from scipy.sparse.linalg import svds
import numpy as np
import serial
import time
import sys
sys.setrecursionlimit(10**8)#Maximum recursion depth exceeded in comparison

inputMatrix =np.array([[192,157,177]])#아두이노로부터 입력받은 데이터

def matrix_to_lof_matrix(inputMatrix):
    lof =LocalOutlierFactor(n_neighbors=5)
    outliers =lof.fit_predict(inputMatrix)
    lof_scores =-lof.negative_outlier_factor_
    return lof_scores

py_serial =serial.Serial(
    port='COM8',
    baudrate=9600 #통신 속도
)

indicator =""
ok =  'o'
end ='e'
X ='x'
Y ='y'
arr =np.array([])
while True:
    #SVD 계산
    indicator =input("")
    for i in range(0,5):
        indicator ="a"
        py_serial.write(indicator.encode())
        print('a')
        if py_serial.readable():
            response =py_serial.readline()
            arr =np.append(arr,np.array([int(response[:len(response)-1].decode())]))
            print(response[:len(response)-1].decode())
        indicator ="b"
        print('b')
        py_serial.write(indicator.encode())
        if py_serial.readable():
            response =py_serial.readline()
            arr =np.append(arr,np.array([int(response[:len(response)-1].decode())]))
            print(response[:len(response)-1].decode())
        indicator ="c"
        print('c')
        py_serial.write(indicator.encode())
        if py_serial.readable():
            response =py_serial.readline()
            arr =np.append(arr,np.array([int(response[:len(response)-1].decode())]))
            print(response[:len(response)-1].decode())
        inputMatrix =np.append(inputMatrix,np.array([arr]),axis=0)
        arr =np.array([])
    U,Sigma,V_T =svds(inputMatrix,k =2)
    SV1,SV2 =np.diag(Sigma)
    print("-------------------------------")
    print(SV1)
    print(SV2)
    print("-------------------------------")
    X ="x"
    py_serial.write(X.encode())

    #py_serial.write(SV1[:len(SV1)-1].encode()) # 디코딩 후, 출력 (가장 끝의 \n을 없애주기위해 슬라이싱 사용)
    #py_serial.write(SV2[:len(SV2)-1].encode())
    #LOF 계산
    lofMatrix =matrix_to_lof_matrix(inputMatrix)
    
    for i in range(len(lofMatrix)):
        if lofMatrix[i]>2:#LOF 2 초과 시 이상치
            py_serial.write(Y.encode())
            py_serial(inputMatrix[i,0][:len(inputMatrix[i,0])-1].encode())
            py_serial(inputMatrix[i,1][:len(inputMatrix[i,1])-1].encode())
            py_serial(inputMatrix[i,2][:len(inputMatrix[i,2])-1].encode())
