require "numo/narray"
include Numo

sci=Numo::DFloat[65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
eng=Numo::DFloat[44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]

print("平均点　　理科：",sci.mean,"\n	　英語：",eng.mean,"\n")
print("標準偏差　理科：",sci.stddev,"\n	　英語：",eng.stddev,"\n")
print("合計点　　理科：",sci.sum,"\n	　英語：",eng.sum,"\n\n")

sci_ave=sci.mean
eng_ave=eng.mean
sci_sdev=sci.stddev
eng_sdev=eng.stddev

puts "偏差値"
puts "理科"

i=0
sci.each{ |x|
	i=i+1
	sci_dev=(x-sci_ave)/(sci_sdev)*10+50
	print("	　",i," ",sci_dev,"\n")
}

puts "英語"

i=0
eng.each{ |x|
	i=i+1
	eng_dev=(x-eng_ave)/(eng_sdev)*10+50
	print("	　",i," ",eng_dev,"\n")
}

print("\n点数が高い順\n理科\n")

sci.sort.reverse.each{ |x|
	print("	　",x,"\n")
}

print("\n英語\n")

eng.sort.reverse.each{ |x|
	print("	　",x,"\n")
}
