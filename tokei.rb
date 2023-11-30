require "narray"

science = NArray.to_na([65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84,70])
english = NArray.to_na([44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84])

p "理科平均 #{science.mean}"
p "英語平均 #{english.mean}"
p "理科標準偏差, #{science.stddev}"
p "英語標準偏差, #{english.stddev}"
p "理科合計 #{science.sum}"
p "英語合計 #{english.sum}"

science.to_a.each_with_index do |v,i|
    p "理科偏差値 #{i+1} #{(v - science.mean) / science.stddev * 10 + 50}"
end

english.to_a.each_with_index do |v,i|
    p "英語偏差値 #{i+1} #{(v - english.mean) / english.stddev * 10 + 50}"
end

p "理科(高い順): #{science.to_a.sort}"
p "英語(高い順): #{english.to_a.sort}"



