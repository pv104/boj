class Solution {
    public int convertToInt(String dest) {
        String[] str = dest.split(":");
        int h = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        return h*60+m;
    }
    public String simulation(String v, String p, String st, String ed, String[] commands) {
        int video_len = convertToInt(v);
        int pos = convertToInt(p);
        int op_start = convertToInt(st);
        int op_end = convertToInt(ed);
        
        for (String command : commands) {
            // 1. 오프닝 건너뛰기
            if(pos >= op_start && pos <= op_end)
                pos = op_end;
            // 2. prev
            if(command.equals("prev")) {
                if(pos < 10)
                    pos = 0;
                else
                    pos -= 10;
            } else if(command.equals("next")) {
                if(video_len - pos < 10)
                    pos = video_len;
                else
                    pos += 10;
            }
        }
        if(pos >= op_start && pos <= op_end)
                pos = op_end;
        Integer h = pos/60;
        String hh = h.toString();
        if(hh.length() == 1)
            hh = "0" + hh;
        Integer m = pos%60;
        String mm = m.toString();
        if(mm.length() == 1)
            mm = "0" + mm;
        return hh+":"+mm;
    }
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = simulation(video_len, pos, op_start, op_end, commands);
        return answer;
    }
}