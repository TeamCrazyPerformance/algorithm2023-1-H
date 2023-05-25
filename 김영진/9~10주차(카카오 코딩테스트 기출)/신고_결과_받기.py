def solution(id_list, report, k):
    answer = []
    ban_list = []
    report = list(set(report))

    report_cnt = {}
    for i in range(len(report)):
        if report_cnt.get(report[i].split()[1]):
            tmp = report_cnt[report[i].split()[1]]
            tmp.append(report[i].split()[0])
            report_cnt.update({report[i].split()[1]: tmp})
        else:
            report_cnt.update({report[i].split()[1]: report[i].split()[0].split()})

    for i in range(len(id_list)):
        answer.append(0)
        if report_cnt.get(id_list[i]) and len(report_cnt[id_list[i]]) >= k:
            ban_list.append(id_list[i])

    report_cnt_num = {}

    for i in range(len(ban_list)):
        for j in range(len(report_cnt[ban_list[i]])):
            if report_cnt_num.get(report_cnt[ban_list[i]][j]):
                tmp = report_cnt_num[report_cnt[ban_list[i]][j]] + 1
                report_cnt_num.update({report_cnt[ban_list[i]][j]: tmp})
            else:
                report_cnt_num.update({report_cnt[ban_list[i]][j]: 1})

    for i in range(len(id_list)):
        if report_cnt_num.get(id_list[i]):
            answer[i] = report_cnt_num[id_list[i]]
    return answer
