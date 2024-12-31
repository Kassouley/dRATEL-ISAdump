import requests
from bs4 import BeautifulSoup

def get_soup_from_request_http(url) :
    response = requests.get(url)
    if response.status_code == 200:
        return BeautifulSoup(response.text, 'html.parser')
    else:
        print(f"Erreur lors de la récupération de la page : {response.status_code}")
        return -1
    
def merge_dics_of_dics(dic1, dic2) :
    merged_dic = dic1.copy()

    for key, value in dic2.items():
        if key in merged_dic:
            for sub_key, sub_value in value.items():
                if sub_key in merged_dic[key]:
                    print(f"Warning: Overwriting value {merged_dic[key][sub_key]} with {sub_value} for key '{key}' and sub-key '{sub_key}'")
                merged_dic[key][sub_key] = sub_value
        else:
            merged_dic[key] = value
    
    return merged_dic


def merge_dicts(dict1, dict2):
    merged_dict = {}
    for key, value in dict1.items():
        if key in dict2:
            merged_dict[key] = value + dict2[key]
        else:
            merged_dict[key] = value

    for key, value in dict2.items():
        if key not in merged_dict:
            merged_dict[key] = value

    return merged_dict

def fuse_without_occ(list1, list2):
    set_list = set(list1)
    for e in list2:
        if e not in set_list:
            list1.append(e)
    return list1

def frag_and_dupli(tab):
    result_tab = []
    for list in tab :
        new_list = []
        max_row = 1
        for element in list:
            rows = element.split("\n")
            max_row = max(max_row, len(rows))
            new_list.append(rows)
        for i in range(len(new_list)):
            while len(new_list[i]) < max_row:
                new_list[i].append(new_list[i][-1])
        result = []
        for i in range(max_row):
            ligne = []
            for j in range(len(list)):
                ligne.append(new_list[j][i])
            result.append(ligne)
        for r in result :    
            result_tab.append(r)
    return result_tab