# encoding: utf-8


# lesson2

# comment
print "Hello World"

=begin
ブロックコメント
=end

print "h2"

# lesson3

print "h2" # 普通に表示
puts "Hello world, again" # 改行付きで表示
p "Hello world 3" # オブジェクト型がわかるように表示 (dump)

print "hoge", "hage", "moge" # 複数指定可能
puts "hoge", "hage", "moge" # 複数指定可能

# lesson4
# 変数と定数

x = 10  # 変数
p x

#end = 5  # 予約語は変数に使えない

EMAIL = "a.shigeru@gmail.com"  # 全部大文字だと定数
# EMAIL = "hoge"; # 上書きはエラー

puts EMAIL


# lesson5 オブジェクト

p "hello".length

# lesson6 クラスとインスタンス

# @see http://www.ruby-doc.org/core-2.0.0/String.html


# lesson7 数値オブジェクト

p 10.1

p Rational(2, 3);

p 5 ** 2
p 5 % 2

p Rational(2, 3) + Rational(5, 6)

# lesson8 数値オブジェクトのメソッド

p 10.5.to_i
p 10.5.to_r
p 10.5.round
p 10.5.ceil
p 10.5.floor
p rand(100)
p Math.sqrt(2);


# lesson9 文字列オブジェクト

x = "hello" # 変数、特殊文字は展開
y = 'hello' # 変数、特殊文字を展開しない

puts "hello\nworld"


name = "tabugchi"
puts "my name is #{name}"

puts "こんにちは"

# lesson10 文字列のメソッド

p "hello".upcase
p "hello".reverse
p "hello".index("l")
p "hello".include?("o");


# lesson11 破壊的メソッド

s = "hello"
s1 = s.upcase # 安全なヤツ
p s, s1 # "hello"

s1 = s.upcase! # 破壊的
p s, s1 # ""


# lesson12 配列

names = ['tagchi', 'jkoji', 'dotinstall']

p names, names[1], names[1..2], names[0...2]
p names[-1] # 後ろから


# lession13 配列

names = ['tagchi', 'jkoji', 'dotinstall']

names[0] = 'tagchi_new'
p names

names[0..1] = 'tagchi_new', 'hoge_new'
p names

names[1,2] = 'a', 'b'
p names

names[1, 0] = ['c']
p names


# lession14 配列の演算

a = [1, 2, 3, 4]
b = [3, 4, 5, 6]

p a & b  # 共通部分のみ出す
p a | b  # 重複無しでマージ
p a - b  # 重複削除
p a + b  # ただのマージ


# lession15 配列のメソッド

a = [8, 5, 3, 4, 5, 6, 7, 0]
p a.uniq, a.sort, a.sort!

# p a.unshift
# p a.push
# p a.shift
# p a.pop

p a.push(10)


# lesson16 ハッシュオブジェクト

sales = {'tanaka' => 100, 'hoge' => 150, 'foo' => 300}
p sales, sales['tanaka']


# lession17 ハッシュのメソッド

sales = {'tanaka' => 100, 'hoge' => 150, 'foo' => 300}
p sales.size, sales.empty?, sales.has_key?('foo'), sales.has_value?(500)


# lession18 日付

t = Time.now
p t, t.year, t.month


t = Time.mktime(2011, 2, 24, 9, 0, 0)
p t + 10 # +10sec
p t.strftime("%Y/%m/%d")


# lesson 19

x = "hoge"
y = 25
printf("%-10s's score is %08d\n", x, y)
z = sprintf("%-10s's score is %08d\n", x, y)
p z


# lesson 20 if

score = 30
if score >= 100 then
    puts "great!"
elsif score > 80
    puts "soso"
else
    puts "not so great"
end


# lesson 21 if

score = 120
puts "great" if score >= 100

puts score > 50 ? "hoge" : "moge"


# lesson 22 比較演算子

# > < >= <= == !=
# =~ # 正規表現演算子
puts "match" if /taguchi/ =~ "my name is taguchi"

# && ||


# lesson 23 case

signal = "yellow"

case signal
when "red"
    puts "red"
when "yellow"
    puts "yellow"
else
    puts "other"
end


# lesson 24 繰り返し

3.times do
    puts 'hoge'
end 

3.times do |i|
    puts 'hoge', i
end 


# lesson 25 繰り返し

users = ["taguchi", "koji", "install"]

for user in users do
    puts user
end

users.each do |user|
    puts user
end

for i in 1..10 do
    puts i
end


# lesson 26 ハッシュの繰り返し

scores = {"taguchi" => 200, "koji" => 150, "install" => 300}
scores.each do |name, score|
    printf("%s score is %d\n", name, score)
end


# lesosn 27 while

i = 1
while i < 10 do
    puts i
    # i = i+1
    i += 1
end

# メソッドの定義

def sing
    puts "lalala"
end

sing
sing()

def sing2(name = "moge")
    printf("%s lalala\n", name)
end

sing2
sing2("hoge")


# lesson 29 メソッドの引数、返り値

def sing3(word='la', num=1)
    for i in 1..num do
        print word
    end
    print "\n"
end

sing3


def sing4(word='la', num=1)
    s = ""
    for i in 1..num do
        s += word
    end

    return s
end

puts sing4('bu', 4)



# lesson 30, 31 クラス

class Monster
    def initialize(name)
        @name = name
        @hp = 100 + rand(100)

        printf("%s's hp is %d\n", @name, @hp)
    end

    def damage
        @hp -= rand(10)
        printf("%s's hp is %d\n", @name, @hp)
    end

    def heal
        @hp += rand(10)
        printf("%s's hp is %d\n", @name, @hp)
    end
end


# lesson 32 insutansu 

slime = Monster.new("slime")

slime.damage
slime.damage
slime.damage
slime.heal
slime.damage
