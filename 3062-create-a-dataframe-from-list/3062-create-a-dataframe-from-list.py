import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    dict = {}
    dict["student_id"] = []
    dict["age"] = []
    for idAndAge in student_data :
        id : int = idAndAge[0]
        age : int = idAndAge[1]
        dict["student_id"].append(id)
        dict["age"].append(age)
    return pd.DataFrame(data=dict)
    