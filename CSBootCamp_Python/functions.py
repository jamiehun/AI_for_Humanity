import openpyxl
import math
# 학년 전체 학생의 평균 : 50점

# 학생들 데이터를 가져옴 (key : 학생이름, value : 점수 딕셔너리)
def get_data_from_excel(filename):
    dic = {}
    wb = openpyxl.load_workbook(filename)
    ws = wb.active
    g = ws.rows
    
    for name, score in g:
        dic[name.value] = score.value
        
    return dic

# 평균, 표준편차, 분산 구하기
def average(scores):
    s = 0
    for score in scores:
        s += score
    return round(s/len(scores), 1)

def variance(scores, avrg):
    s = 0
    for score in scores:
        s += (score - avrg) ** 2
    return round(s/len(scores), 1)

def std_dev(variance):
    return round(math.sqrt(variance), 1)

# 학생들 성적 비교
def evaluateClass(avrg, total_avrg, std_dev, sd):
    if avrg < total_avrg and std_dev > sd:
        print("성적 저조, 편차 너무 큼")
    elif avrg > total_avrg and std_dev > sd:
        print("성적 평균이상, 편차 큼")
    elif avrg < total_avrg and std_dev < sd:
        print("성적 저조, 편차 적음")
    elif avrg > total_avrg and std_dev < sd:
        print("성적 평균이상, 편차 적음")
