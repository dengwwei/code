# 链接地址：

[String (Java SE 11 & JDK 11 ) (runoob.com)](https://www.runoob.com/manual/jdk11api/java.base/java/lang/String.html)

# String类

当对字符串进行修改的时候，需要使用`StringBuffer` 和 `StringBuilder `类。

和`String` 类不同的是，`StringBuffer` 和` StringBuilder` 类的对象能够被多次的修改，并且不产生新的未使用对象。

在使用 `StringBuffer` 类时，每次都会对 `StringBuffer` 对象本身进行操作，而不是生成新的对象，所以如果需要对字符串进行修改推荐使用 `StringBuffer`。

`StringBuilder `类在 Java 5 中被提出，它和 `StringBuffer` 之间的最大不同在于 `StringBuilder` 的方法不是线程安全的（不能同步访问）。

由于 `StringBuilder` 相较于 `StringBuffer` 有速度优势，所以多数情况下建议使用 `StringBuilder` 类。

# 构造方法

- | `String()`                                                   | 初始化新创建的 `String`对象，使其表示空字符序列。            |
  | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | `String(byte[] bytes)`                                       | 通过使用平台的默认字符集解码指定的字节数组构造新的 `String` 。 |
  | `String(byte[] ascii, int hibyte)`                           | **已过时。**此方法无法将字节正确转换为字符。                 |
  | `String(byte[] bytes, int offset, int length)`               | 通过使用平台的默认字符集解码指定的字节子阵列来构造新的 `String` 。 |
  | `String(byte[] ascii, int hibyte, int offset, int count)`    | **已过时。**此方法无法将字节正确转换为字符。                 |
  | `String(byte[] bytes, int offset, int length, String charsetName)` | 通过使用指定的字符集解码指定的字节子 `String`构造新的 `String` 。 |
  | `String(byte[] bytes, int offset, int length, Charset charset)` | 通过使用指定的[charset](https://www.runoob.com/manual/jdk11api/java.base/java/nio/charset/Charset.html)解码指定的字节子`String`构造新的[String](https://www.runoob.com/manual/jdk11api/java.base/java/nio/charset/Charset.html) 。 |
  | `String(byte[] bytes, String charsetName)`                   | 构造一个新的`String`由指定用指定的字节的数组解码[charset](https://www.runoob.com/manual/jdk11api/java.base/java/nio/charset/Charset.html) 。 |
  | `String(byte[] bytes, Charset charset)`                      | 构造一个新的`String`由指定用指定的字节的数组解码[charset](https://www.runoob.com/manual/jdk11api/java.base/java/nio/charset/Charset.html) 。 |
  | `String(char[] value)`                                       | 分配新的 `String` ，使其表示当前包含在字符数组参数中的字符序列。 |
  | `String(char[] value, int offset, int count)`                | 分配一个新的 `String` ，其中包含字符数组参数的子数组中的字符。 |
  | `String(int[] codePoints, int offset, int count)`            | 分配新的 `String` ，其中包含 [Unicode code point](https://www.runoob.com/manual/jdk11api/java.base/java/lang/Character.html#unicode)数组参数的子数组中的字符。 |
  | `String(String original)`                                    | 初始化新创建的`String`对象，使其表示与参数相同的字符序列; 换句话说，新创建的字符串是参数字符串的副本。 |
  | `String(StringBuffer buffer)`                                | 分配一个新字符串，其中包含当前包含在字符串缓冲区参数中的字符序列。 |
  | `String(StringBuilder builder)`                              | 分配一个新字符串，其中包含当前包含在字符串构建器参数中的字符序列。 |

# 详细方法

| 变量和类型       | 方法                                                         | 描述                                                         |
| :--------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| `char`           | `charAt(int index)`                                          | 返回指定索引处的 `char`值。                                  |
| `IntStream`      | `chars()`                                                    | 返回 `int`的流，将此序列中的 `char`值零扩展。                |
| `int`            | `codePointAt(int index)`                                     | 返回指定索引处的字符（Unicode代码点）。                      |
| `int`            | `codePointBefore(int index)`                                 | 返回指定索引之前的字符（Unicode代码点）。                    |
| `int`            | `codePointCount(int beginIndex, int endIndex)`               | 返回此 `String`的指定文本范围内的Unicode代码点数。           |
| `IntStream`      | `codePoints()`                                               | 返回此序列中的代码点值流。                                   |
| `int`            | `compareTo(String anotherString)`                            | 按字典顺序比较两个字符串。                                   |
| `int`            | `compareToIgnoreCase(String str)`                            | 按字典顺序比较两个字符串，忽略大小写差异。                   |
| `String`         | `concat(String str)`                                         | 将指定的字符串连接到此字符串的末尾。                         |
| `boolean`        | `contains(CharSequence s)`                                   | 当且仅当此字符串包含指定的char值序列时，才返回true。         |
| `boolean`        | `contentEquals(CharSequence cs)`                             | 将此字符串与指定的 `CharSequence` 。                         |
| `boolean`        | `contentEquals(StringBuffer sb)`                             | 将此字符串与指定的 `StringBuffer` 。                         |
| `static String`  | `copyValueOf(char[] data)`                                   | 相当于 [`valueOf(char[\])`](https://www.runoob.com/manual/jdk11api/java.base/java/lang/String.html#valueOf(char[])) 。 |
| `static String`  | `copyValueOf(char[] data, int offset, int count)`            | 相当于 [`valueOf(char[\], int, int)`](https://www.runoob.com/manual/jdk11api/java.base/java/lang/String.html#valueOf(char[],int,int)) 。 |
| `boolean`        | `endsWith(String suffix)`                                    | 测试此字符串是否以指定的后缀结尾。                           |
| `boolean`        | `equals(Object anObject)`                                    | 将此字符串与指定的对象进行比较。                             |
| `boolean`        | `equalsIgnoreCase(String anotherString)`                     | 将此 `String`与另一个 `String`比较，忽略了大小写。           |
| `static String`  | `format(String format, Object... args)`                      | 使用指定的格式字符串和参数返回格式化字符串。                 |
| `static String`  | `format(Locale l, String format, Object... args)`            | 使用指定的语言环境，格式字符串和参数返回格式化的字符串。     |
| `byte[]`         | `getBytes()`                                                 | 使用平台的默认字符集将此 `String`编码为字节序列，将结果存储到新的字节数组中。 |
| `void`           | `getBytes(int srcBegin, int srcEnd, byte[] dst, int dstBegin)` | **已过时。**此方法无法将字符正确转换为字节。                 |
| `byte[]`         | `getBytes(String charsetName)`                               | 使用命名的字符集将此 `String`编码为字节序列，将结果存储到新的字节数组中。 |
| `byte[]`         | `getBytes(Charset charset)`                                  | 使用给定的[charset](https://www.runoob.com/manual/jdk11api/java.base/java/nio/charset/Charset.html)将此`String`编码为字节序列，将结果存储到新的字节数组中。 |
| `void`           | `getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin)` | 将此字符串中的字符复制到目标字符数组中。                     |
| `int`            | `hashCode()`                                                 | 返回此字符串的哈希码。                                       |
| `int`            | `indexOf(int ch)`                                            | 返回指定字符第一次出现的字符串中的索引。                     |
| `int`            | `indexOf(int ch, int fromIndex)`                             | 返回指定字符第一次出现的此字符串中的索引，从指定索引处开始搜索。 |
| `int`            | `indexOf(String str)`                                        | 返回指定子字符串第一次出现的字符串中的索引。                 |
| `int`            | `indexOf(String str, int fromIndex)`                         | 从指定的索引处开始，返回指定子字符串第一次出现的字符串中的索引。 |
| `String`         | `intern()`                                                   | 返回字符串对象的规范表示。                                   |
| `boolean`        | `isBlank()`                                                  | 如果字符串为空或仅包含 [`white space`](https://www.runoob.com/manual/jdk11api/java.base/java/lang/Character.html#isWhitespace(int))代码点，则返回 `true` ，否则 `false` 。 |
| `boolean`        | `isEmpty()`                                                  | 返回 `true` ，当且仅当， [`length()`](https://www.runoob.com/manual/jdk11api/java.base/java/lang/String.html#length())是 `0` 。 |
| `static String`  | `join(CharSequence delimiter, CharSequence... elements)`     | 返回由 `CharSequence elements`的副本组成的新String，该副本与指定的 `delimiter`的副本连接在一起。 |
| `static String`  | `join(CharSequence delimiter, Iterable<? extends CharSequence> elements)` | 返回由 `String`的副本组成的新 `String` ，其中 `CharSequence elements`指定的 `delimiter`的副本。 |
| `int`            | `lastIndexOf(int ch)`                                        | 返回指定字符最后一次出现的字符串中的索引。                   |
| `int`            | `lastIndexOf(int ch, int fromIndex)`                         | 返回指定字符最后一次出现的字符串中的索引，从指定的索引开始向后搜索。 |
| `int`            | `lastIndexOf(String str)`                                    | 返回指定子字符串最后一次出现的字符串中的索引。               |
| `int`            | `lastIndexOf(String str, int fromIndex)`                     | 返回指定子字符串最后一次出现的字符串中的索引，从指定索引开始向后搜索。 |
| `int`            | `length()`                                                   | 返回此字符串的长度。                                         |
| `Stream<String>` | `lines()`                                                    | 返回从此字符串中提取的行的流，由行终止符分隔。               |
| `boolean`        | `matches(String regex)`                                      | 判断此字符串是否与给定的 [regular expression](https://www.runoob.com/manual/jdk11api/java.base/java/util/regex/Pattern.html#sum)匹配。 |
| `int`            | `offsetByCodePoints(int index, int codePointOffset)`         | 返回此 `String`中的索引，该索引从给定的 `index`偏移 `codePointOffset`代码点。 |
| `boolean`        | `regionMatches(boolean ignoreCase, int toffset, String other, int ooffset, int len)` | 测试两个字符串区域是否相等。                                 |
| `boolean`        | `regionMatches(int toffset, String other, int ooffset, int len)` | 测试两个字符串区域是否相等。                                 |
| `String`         | `repeat(int count)`                                          | 返回一个字符串，其值为此字符串的串联重复 `count`次。         |
| `String`         | `replace(char oldChar, char newChar)`                        | 返回从替换所有出现的导致一个字符串 `oldChar`在此字符串 `newChar` 。 |
| `String`         | `replace(CharSequence target, CharSequence replacement)`     | 将此字符串中与文字目标序列匹配的每个子字符串替换为指定的文字替换序列。 |
| `String`         | `replaceAll(String regex, String replacement)`               | 将给定替换的给定 [regular expression](https://www.runoob.com/manual/jdk11api/java.base/java/util/regex/Pattern.html#sum)匹配的此字符串的每个子字符串替换。 |
| `String`         | `replaceFirst(String regex, String replacement)`             | 将给定替换的给定 [regular expression](https://www.runoob.com/manual/jdk11api/java.base/java/util/regex/Pattern.html#sum)匹配的此字符串的第一个子字符串替换。 |
| `String[]`       | `split(String regex)`                                        | 将此字符串拆分为给定 [regular expression的](https://www.runoob.com/manual/jdk11api/java.base/java/util/regex/Pattern.html#sum)匹配 [项](https://www.runoob.com/manual/jdk11api/java.base/java/util/regex/Pattern.html#sum) 。 |
| `String[]`       | `split(String regex, int limit)`                             | 将此字符串拆分为给定 [regular expression的](https://www.runoob.com/manual/jdk11api/java.base/java/util/regex/Pattern.html#sum)匹配 [项](https://www.runoob.com/manual/jdk11api/java.base/java/util/regex/Pattern.html#sum) 。 |
| `boolean`        | `startsWith(String prefix)`                                  | 测试此字符串是否以指定的前缀开头。                           |
| `boolean`        | `startsWith(String prefix, int toffset)`                     | 测试从指定索引开始的此字符串的子字符串是否以指定的前缀开头。 |
| `String`         | `strip()`                                                    | 返回一个字符串，其值为此字符串，并删除了所有前导和尾随 [`white space`](https://www.runoob.com/manual/jdk11api/java.base/java/lang/Character.html#isWhitespace(int)) 。 |
| `String`         | `stripLeading()`                                             | 返回一个字符串，其值为此字符串，并删除了所有前导 [`white space`](https://www.runoob.com/manual/jdk11api/java.base/java/lang/Character.html#isWhitespace(int)) 。 |
| `String`         | `stripTrailing()`                                            | 返回一个字符串，其值为此字符串，并删除所有尾随 [`white space`](https://www.runoob.com/manual/jdk11api/java.base/java/lang/Character.html#isWhitespace(int)) 。 |
| `CharSequence`   | `subSequence(int beginIndex, int endIndex)`                  | 返回作为此序列的子序列的字符序列。                           |
| `String`         | `substring(int beginIndex)`                                  | 返回一个字符串，该字符串是此字符串的子字符串。               |
| `String`         | `substring(int beginIndex, int endIndex)`                    | 返回一个字符串，该字符串是此字符串的子字符串。               |
| `char[]`         | `toCharArray()`                                              | 将此字符串转换为新的字符数组。                               |
| `String`         | `toLowerCase()`                                              | 使用默认语言环境的规则将此 `String`所有字符转换为小写。      |
| `String`         | `toLowerCase(Locale locale)`                                 | 使用给定 `Locale`的规则将此 `String`所有字符转换为 `Locale` 。 |
| `String`         | `toString()`                                                 | 这个对象（已经是一个字符串！）                               |
| `String`         | `toUpperCase()`                                              | 使用默认语言环境的规则将此 `String`所有字符转换为大写。      |
| `String`         | `toUpperCase(Locale locale)`                                 | 使用给定 `Locale`的规则将此 `String`所有字符转换为大写。     |
| `String`         | `trim()`                                                     | 返回一个字符串，其值为此字符串，删除了所有前导和尾随空格，其中space被定义为其代码点小于或等于 `'U+0020'` （空格字符）的任何字符。 |
| `static String`  | `valueOf(boolean b)`                                         | 返回 `boolean`参数的字符串表示形式。                         |
| `static String`  | `valueOf(char c)`                                            | 返回 `char`参数的字符串表示形式。                            |
| `static String`  | `valueOf(char[] data)`                                       | 返回 `char`数组参数的字符串表示形式。                        |
| `static String`  | `valueOf(char[] data, int offset, int count)`                | 返回 `char`数组参数的特定子数组的字符串表示形式。            |
| `static String`  | `valueOf(double d)`                                          | 返回 `double`参数的字符串表示形式。                          |
| `static String`  | `valueOf(float f)`                                           | 返回 `float`参数的字符串表示形式。                           |
| `static String`  | `valueOf(int i)`                                             | 返回 `int`参数的字符串表示形式。                             |
| `static String`  | `valueOf(long l)`                                            | 返回 `long`参数的字符串表示形式。                            |
| `static String`  | `valueOf(Object obj)`                                        | 返回 `Object`参数的字符串表示形式。                          |

# 常用方法：

1· `char charAt(int index)` 返回索引值，可类似数组下标的使用方法。

2·`int compare To(Object o)` 将这个字符串与另一个对象比较。含有另一个类似的方法。

3·`boolean equals(Object ob)` 与指定对象比较

4· `int indexof()` 有三种构造，`int ch` 为字符在字符串的第一次索引，`int ch int formIndex` 从一个指定位置开始索引，`String str` 字符串的索引 ，`String str int fromIndex` 类比上。

5·`String[] split(String regex)` 根据给定正则表达式的匹配拆分此字符串。例，输入的字符串有空格，可利用这个只将空格输入数组。`[String[\] split(String regex, int limit)]` 暂时没用过。

6·`[String substring(int beginIndex)]`返回一个新的字符串，它是此字符串的一个子字符串。从beginindex到结束位

7·`String substring(int beginIndex，int endIndex)` 设置开始到结束，用于剪切字符串。

8·`char[]toCharArray()` 将此字符串转换为一个新的字符数组。

9·`isEmpty() `判断是否为空

10·`BufferedReader br = new BufferedReader(new                       InputStreamReader(System.in));` 常用输入`int read()` 需要强制类型转换，`String readline()` 输入字符串，利用`append ` 等添加的方法，其添加内容为`input.next等` 。

# `StringBuffer` 方法

| 1    | `public StringBuffer append(String s)` 将指定的字符串追加到此字符序列。 |
| ---- | ------------------------------------------------------------ |
| 2    | `public StringBuffer reverse()`  将此字符序列用其反转形式取代。 |
| 3    | `public delete(int start, int end) `移除此序列的子字符串中的字符。 |
| 4    | `public insert(int offset, int i)` 将 `int` 参数的字符串表示形式插入此序列中。 |
| 5    | `insert(int offset, String str)` 将 `str` 参数的字符串插入此序列中。 |
| 6    | `replace(int start, int end, String str)` 使用给定 `String` 中的字符替换此序列的子字符串中的字符。 |

# `Scanner` 类的小点

next():

- 1、一定要读取到有效字符后才可以结束输入。
- 2、对输入有效字符之前遇到的空白，next() 方法会自动将其去掉。
- 3、只有输入有效字符后才将其后面输入的空白作为分隔符或者结束符。
- next() 不能得到带有空格的字符串，空格会结束输入。

nextLine()：

- 1、以Enter为结束符,也就是说 nextLine()方法返回的是输入回车之前的所有字符。

- 2、可以获得空白。

  `hasnext` 用来判断是否还有输入。