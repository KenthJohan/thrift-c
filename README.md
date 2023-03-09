# Thrift compact protocol parser

* Stack based parser
* No recursion
* Maximum depth configurable
* No dependecies
* Not fully implemented. Missing SET and MAP.

## Usage
```c
thrift_api.malloc_ = malloc;
uint8_t const * current = data; // Pointer to thrift compact binary data
thrift_type_t type;
thrift_value_t value;
int64_t id;
thrift_cursor_t cursor = {0};
cursor.stack_size = 64;
thrift_cursor_init(&cursor);
while(current)
{
	current = thrift_cursor_next(&cursor, current, data+l, &type, &id, &value);
}
```

### Demo
```bash
gcc demo_test1.c thrift.c
```
This is just a minor test that parses a header of Apache Parquet file.
<details>
<summary>demo_test1.c output</summary>
  
|N   |sp|id|type  |value                |
|----|--|--|------|---------------------|
|0000|00|01|I32   |1                                |
|0001|00|02|LIST  |14 of STRUCT                     |
|0002|01|00|STRUCT| {                               |
|0003|02|04|BINARY|  hive_schema                    |
|0004|02|05|I32   |  13                             |
|0005|01|05|STOP  | }                               |
|0006|01|01|STRUCT| {                               |
|0007|02|01|I32   |  3                              |
|0008|02|03|I32   |  1                              |
|0009|02|04|BINARY|  registration_dttm              |
|0010|01|04|STOP  | }                               |
|0011|01|02|STRUCT| {                               |
|0012|02|01|I32   |  1                              |
|0013|02|03|I32   |  1                              |
|0014|02|04|BINARY|  id                             |
|0015|01|04|STOP  | }                               |
|0016|01|03|STRUCT| {                               |
|0017|02|01|I32   |  6                              |
|0018|02|03|I32   |  1                              |
|0019|02|04|BINARY|  first_name                     |
|0020|02|06|I32   |  0                              |
|0021|01|06|STOP  | }                               |
|0022|01|04|STRUCT| {                               |
|0023|02|01|I32   |  6                              |
|0024|02|03|I32   |  1                              |
|0025|02|04|BINARY|  last_name                      |
|0026|02|06|I32   |  0                              |
|0027|01|06|STOP  | }                               |
|0028|01|05|STRUCT| {                               |
|0029|02|01|I32   |  6                              |
|0030|02|03|I32   |  1                              |
|0031|02|04|BINARY|  email                          |
|0032|02|06|I32   |  0                              |
|0033|01|06|STOP  | }                               |
|0034|01|06|STRUCT| {                               |
|0035|02|01|I32   |  6                              |
|0036|02|03|I32   |  1                              |
|0037|02|04|BINARY|  gender                         |
|0038|02|06|I32   |  0                              |
|0039|01|06|STOP  | }                               |
|0040|01|07|STRUCT| {                               |
|0041|02|01|I32   |  6                              |
|0042|02|03|I32   |  1                              |
|0043|02|04|BINARY|  ip_address                     |
|0044|02|06|I32   |  0                              |
|0045|01|06|STOP  | }                               |
|0046|01|08|STRUCT| {                               |
|0047|02|01|I32   |  6                              |
|0048|02|03|I32   |  1                              |
|0049|02|04|BINARY|  cc                             |
|0050|02|06|I32   |  0                              |
|0051|01|06|STOP  | }                               |
|0052|01|09|STRUCT| {                               |
|0053|02|01|I32   |  6                              |
|0054|02|03|I32   |  1                              |
|0055|02|04|BINARY|  country                        |
|0056|02|06|I32   |  0                              |
|0057|01|06|STOP  | }                               |
|0058|01|10|STRUCT| {                               |
|0059|02|01|I32   |  6                              |
|0060|02|03|I32   |  1                              |
|0061|02|04|BINARY|  birthdate                      |
|0062|02|06|I32   |  0                              |
|0063|01|06|STOP  | }                               |
|0064|01|11|STRUCT| {                               |
|0065|02|01|I32   |  5                              |
|0066|02|03|I32   |  1                              |
|0067|02|04|BINARY|  salary                         |
|0068|01|04|STOP  | }                               |
|0069|01|12|STRUCT| {                               |
|0070|02|01|I32   |  6                              |
|0071|02|03|I32   |  1                              |
|0072|02|04|BINARY|  title                          |
|0073|02|06|I32   |  0                              |
|0074|01|06|STOP  | }                               |
|0075|01|13|STRUCT| {                               |
|0076|02|01|I32   |  6                              |
|0077|02|03|I32   |  1                              |
|0078|02|04|BINARY|  comments                       |
|0079|02|06|I32   |  0                              |
|0080|01|06|STOP  | }                               |
|0081|00|06|STOP  |}                                |
|0082|00|03|I64   |1000                             |
|0083|00|04|LIST  |1 of STRUCT                      |
|0084|01|00|STRUCT| {                               |
|0085|02|01|LIST  |  13 of STRUCT                   |
|0086|03|00|STRUCT|   {                             |
|0087|04|02|I64   |    4                            |
|0088|04|03|STRUCT|    {                            |
|0089|05|01|I32   |     3                           |
|0090|05|02|LIST  |     3 of I32                    |
|0091|06|00|I32   |      4                          |
|0092|06|01|I32   |      2                          |
|0093|06|02|I32   |      3                          |
|0094|05|02|STOP  |     }                           |
|0095|05|03|LIST  |     1 of BINARY                 |
|0096|06|00|BINARY|      registration_dttm          |
|0097|05|00|STOP  |     }                           |
|0098|05|04|I32   |     0                           |
|0099|05|05|I64   |     1000                        |
|0100|05|06|I64   |     13270                       |
|0101|05|07|I64   |     13270                       |
|0102|05|09|I64   |     4                           |
|0103|05|12|STRUCT|     {                           |
|0104|06|01|BINARY|                                 |
|0105|06|02|BINARY|                                 |
|0106|06|03|I64   |      0                          |
|0107|05|03|STOP  |     }                           |
|0108|04|03|STOP  |    }                            |
|0109|03|03|STOP  |   }                             |
|0110|03|01|STRUCT|   {                             |
|0111|04|02|I64   |    13274                        |
|0112|04|03|STRUCT|    {                            |
|0113|05|01|I32   |     1                           |
|0114|05|02|LIST  |     3 of I32                    |
|0115|06|00|I32   |      0                          |
|0116|06|01|I32   |      4                          |
|0117|06|02|I32   |      3                          |
|0118|05|02|STOP  |     }                           |
|0119|05|03|LIST  |     1 of BINARY                 |
|0120|06|00|BINARY|      id                         |
|0121|05|00|STOP  |     }                           |
|0122|05|04|I32   |     0                           |
|0123|05|05|I64   |     1000                        |
|0124|05|06|I64   |     4043                        |
|0125|05|07|I64   |     4043                        |
|0126|05|09|I64   |     13274                       |
|0127|05|12|STRUCT|     {                           |
|0128|06|01|BINARY|      ▒                         |
|0129|06|02|BINARY|                                |
|0130|06|03|I64   |      0                          |
|0131|05|03|STOP  |     }                           |
|0132|04|03|STOP  |    }                            |
|0133|03|03|STOP  |   }                             |
|0134|03|02|STRUCT|   {                             |
|0135|04|02|I64   |    17317                        |
|0136|04|03|STRUCT|    {                            |
|0137|05|01|I32   |     6                           |
|0138|05|02|LIST  |     3 of I32                    |
|0139|06|00|I32   |      4                          |
|0140|06|01|I32   |      2                          |
|0141|06|02|I32   |      3                          |
|0142|05|02|STOP  |     }                           |
|0143|05|03|LIST  |     1 of BINARY                 |
|0144|06|00|BINARY|      first_name                 |
|0145|05|00|STOP  |     }                           |
|0146|05|04|I32   |     0                           |
|0147|05|05|I64   |     1000                        |
|0148|05|06|I64   |     2988                        |
|0149|05|07|I64   |     2988                        |
|0150|05|09|I64   |     17317                       |
|0151|05|12|STRUCT|     {                           |
|0152|06|01|BINARY|      Willie                     |
|0153|06|02|BINARY|                                 |
|0154|06|03|I64   |      0                          |
|0155|05|03|STOP  |     }                           |
|0156|04|03|STOP  |    }                            |
|0157|03|03|STOP  |   }                             |
|0158|03|03|STRUCT|   {                             |
|0159|04|02|I64   |    20305                        |
|0160|04|03|STRUCT|    {                            |
|0161|05|01|I32   |     6                           |
|0162|05|02|LIST  |     3 of I32                    |
|0163|06|00|I32   |      4                          |
|0164|06|01|I32   |      2                          |
|0165|06|02|I32   |      3                          |
|0166|05|02|STOP  |     }                           |
|0167|05|03|LIST  |     1 of BINARY                 |
|0168|06|00|BINARY|      last_name                  |
|0169|05|00|STOP  |     }                           |
|0170|05|04|I32   |     0                           |
|0171|05|05|I64   |     1000                        |
|0172|05|06|I64   |     3550                        |
|0173|05|07|I64   |     3550                        |
|0174|05|09|I64   |     20305                       |
|0175|05|12|STRUCT|     {                           |
|0176|06|01|BINARY|      Young                      |
|0177|06|02|BINARY|      Adams                      |
|0178|06|03|I64   |      0                          |
|0179|05|03|STOP  |     }                           |
|0180|04|03|STOP  |    }                            |
|0181|03|03|STOP  |   }                             |
|0182|03|04|STRUCT|   {                             |
|0183|04|02|I64   |    23855                        |
|0184|04|03|STRUCT|    {                            |
|0185|05|01|I32   |     6                           |
|0186|05|02|LIST  |     3 of I32                    |
|0187|06|00|I32   |      0                          |
|0188|06|01|I32   |      4                          |
|0189|06|02|I32   |      3                          |
|0190|05|02|STOP  |     }                           |
|0191|05|03|LIST  |     1 of BINARY                 |
|0192|06|00|BINARY|      email                      |
|0193|05|00|STOP  |     }                           |
|0194|05|04|I32   |     0                           |
|0195|05|05|I64   |     1000                        |
|0196|05|06|I64   |     24688                       |
|0197|05|07|I64   |     24688                       |
|0198|05|09|I64   |     23855                       |
|0199|05|12|STRUCT|     {                           |
|0200|06|01|BINARY|      wweaver2r@google.de        |
|0201|06|02|BINARY|                                 |
|0202|06|03|I64   |      0                          |
|0203|05|03|STOP  |     }                           |
|0204|04|03|STOP  |    }                            |
|0205|03|03|STOP  |   }                             |
|0206|03|05|STRUCT|   {                             |
|0207|04|02|I64   |    48543                        |
|0208|04|03|STRUCT|    {                            |
|0209|05|01|I32   |     6                           |
|0210|05|02|LIST  |     3 of I32                    |
|0211|06|00|I32   |      4                          |
|0212|06|01|I32   |      2                          |
|0213|06|02|I32   |      3                          |
|0214|05|02|STOP  |     }                           |
|0215|05|03|LIST  |     1 of BINARY                 |
|0216|06|00|BINARY|      gender                     |
|0217|05|00|STOP  |     }                           |
|0218|05|04|I32   |     0                           |
|0219|05|05|I64   |     1000                        |
|0220|05|06|I64   |     328                         |
|0221|05|07|I64   |     328                         |
|0222|05|09|I64   |     48543                       |
|0223|05|12|STRUCT|     {                           |
|0224|06|01|BINARY|      Male                       |
|0225|06|02|BINARY|                                 |
|0226|06|03|I64   |      0                          |
|0227|05|03|STOP  |     }                           |
|0228|04|03|STOP  |    }                            |
|0229|03|03|STOP  |   }                             |
|0230|03|06|STRUCT|   {                             |
|0231|04|02|I64   |    48871                        |
|0232|04|03|STRUCT|    {                            |
|0233|05|01|I32   |     6                           |
|0234|05|02|LIST  |     3 of I32                    |
|0235|06|00|I32   |      0                          |
|0236|06|01|I32   |      4                          |
|0237|06|02|I32   |      3                          |
|0238|05|02|STOP  |     }                           |
|0239|05|03|LIST  |     1 of BINARY                 |
|0240|06|00|BINARY|      ip_address                 |
|0241|05|00|STOP  |     }                           |
|0242|05|04|I32   |     0                           |
|0243|05|05|I64   |     1000                        |
|0244|05|06|I64   |     17352                       |
|0245|05|07|I64   |     17352                       |
|0246|05|09|I64   |     48871                       |
|0247|05|12|STRUCT|     {                           |
|0248|06|01|BINARY|      99.159.168.233             |
|0249|06|02|BINARY|      0.14.221.162               |
|0250|06|03|I64   |      0                          |
|0251|05|03|STOP  |     }                           |
|0252|04|03|STOP  |    }                            |
|0253|03|03|STOP  |   }                             |
|0254|03|07|STRUCT|   {                             |
|0255|04|02|I64   |    66223                        |
|0256|04|03|STRUCT|    {                            |
|0257|05|01|I32   |     6                           |
|0258|05|02|LIST  |     3 of I32                    |
|0259|06|00|I32   |      0                          |
|0260|06|01|I32   |      4                          |
|0261|06|02|I32   |      3                          |
|0262|05|02|STOP  |     }                           |
|0263|05|03|LIST  |     1 of BINARY                 |
|0264|06|00|BINARY|      cc                         |
|0265|05|00|STOP  |     }                           |
|0266|05|04|I32   |     0                           |
|0267|05|05|I64   |     1000                        |
|0268|05|06|I64   |     15463                       |
|0269|05|07|I64   |     15463                       |
|0270|05|09|I64   |     66223                       |
|0271|05|12|STRUCT|     {                           |
|0272|06|01|BINARY|      67718647521473678          |
|0273|06|02|BINARY|                                 |
|0274|06|03|I64   |      0                          |
|0275|05|03|STOP  |     }                           |
|0276|04|03|STOP  |    }                            |
|0277|03|03|STOP  |   }                             |
|0278|03|08|STRUCT|   {                             |
|0279|04|02|I64   |    81686                        |
|0280|04|03|STRUCT|    {                            |
|0281|05|01|I32   |     6                           |
|0282|05|02|LIST  |     3 of I32                    |
|0283|06|00|I32   |      4                          |
|0284|06|01|I32   |      2                          |
|0285|06|02|I32   |      3                          |
|0286|05|02|STOP  |     }                           |
|0287|05|03|LIST  |     1 of BINARY                 |
|0288|06|00|BINARY|      country                    |
|0289|05|00|STOP  |     }                           |
|0290|05|04|I32   |     0                           |
|0291|05|05|I64   |     1000                        |
|0292|05|06|I64   |     2450                        |
|0293|05|07|I64   |     2450                        |
|0294|05|09|I64   |     81686                       |
|0295|05|12|STRUCT|     {                           |
|0296|06|01|BINARY|      Zimbabwe                   |
|0297|06|02|BINARY|      "Bonaire                   |
|0298|06|03|I64   |      0                          |
|0299|05|03|STOP  |     }                           |
|0300|04|03|STOP  |    }                            |
|0301|03|03|STOP  |   }                             |
|0302|03|09|STRUCT|   {                             |
|0303|04|02|I64   |    84136                        |
|0304|04|03|STRUCT|    {                            |
|0305|05|01|I32   |     6                           |
|0306|05|02|LIST  |     3 of I32                    |
|0307|06|00|I32   |      0                          |
|0308|06|01|I32   |      4                          |
|0309|06|02|I32   |      3                          |
|0310|05|02|STOP  |     }                           |
|0311|05|03|LIST  |     1 of BINARY                 |
|0312|06|00|BINARY|      birthdate                  |
|0313|05|00|STOP  |     }                           |
|0314|05|04|I32   |     0                           |
|0315|05|05|I64   |     1000                        |
|0316|05|06|I64   |     11267                       |
|0317|05|07|I64   |     11267                       |
|0318|05|09|I64   |     84136                       |
|0319|05|12|STRUCT|     {                           |
|0320|06|01|BINARY|      9/9/1981                   |
|0321|06|02|BINARY|                                 |
|0322|06|03|I64   |      0                          |
|0323|05|03|STOP  |     }                           |
|0324|04|03|STOP  |    }                            |
|0325|03|03|STOP  |   }                             |
|0326|03|10|STRUCT|   {                             |
|0327|04|02|I64   |    95403                        |
|0328|04|03|STRUCT|    {                            |
|0329|05|01|I32   |     5                           |
|0330|05|02|LIST  |     3 of I32                    |
|0331|06|00|I32   |      0                          |
|0332|06|01|I32   |      4                          |
|0333|06|02|I32   |      3                          |
|0334|05|02|STOP  |     }                           |
|0335|05|03|LIST  |     1 of BINARY                 |
|0336|06|00|BINARY|      salary                     |
|0337|05|00|STOP  |     }                           |
|0338|05|04|I32   |     0                           |
|0339|05|05|I64   |     1000                        |
|0340|05|06|I64   |     7631                        |
|0341|05|07|I64   |     7631                        |
|0342|05|09|I64   |     95403                       |
|0343|05|12|STRUCT|     {                           |
|0344|06|01|BINARY|      \▒▒▒~A                   |
|0345|06|02|BINARY|      ▒▒Q▒>.▒@                   |
|0346|06|03|I64   |      68                         |
|0347|05|03|STOP  |     }                           |
|0348|04|03|STOP  |    }                            |
|0349|03|03|STOP  |   }                             |
|0350|03|11|STRUCT|   {                             |
|0351|04|02|I64   |    103034                       |
|0352|04|03|STRUCT|    {                            |
|0353|05|01|I32   |     6                           |
|0354|05|02|LIST  |     3 of I32                    |
|0355|06|00|I32   |      4                          |
|0356|06|01|I32   |      2                          |
|0357|06|02|I32   |      3                          |
|0358|05|02|STOP  |     }                           |
|0359|05|03|LIST  |     1 of BINARY                 |
|0360|06|00|BINARY|      title                      |
|0361|05|00|STOP  |     }                           |
|0362|05|04|I32   |     0                           |
|0363|05|05|I64   |     1000                        |
|0364|05|06|I64   |     5174                        |
|0365|05|07|I64   |     5174                        |
|0366|05|09|I64   |     103034                      |
|0367|05|12|STRUCT|     {                           |
|0368|06|01|BINARY|      Web Developer IV           |
|0369|06|02|BINARY|                                 |
|0370|06|03|I64   |      0                          |
|0371|05|03|STOP  |     }                           |
|0372|04|03|STOP  |    }                            |
|0373|03|03|STOP  |   }                             |
|0374|03|12|STRUCT|   {                             |
|0375|04|02|I64   |    108208                       |
|0376|04|03|STRUCT|    {                            |
|0377|05|01|I32   |     6                           |
|0378|05|02|LIST  |     3 of I32                    |
|0379|06|00|I32   |      4                          |
|0380|06|01|I32   |      2                          |
|0381|06|02|I32   |      3                          |
|0382|05|02|STOP  |     }                           |
|0383|05|03|LIST  |     1 of BINARY                 |
|0384|06|00|BINARY|      comments                   |
|0385|05|00|STOP  |     }                           |
|0386|05|04|I32   |     0                           |
|0387|05|05|I64   |     1000                        |
|0388|05|06|I64   |     4288                        |
|0389|05|07|I64   |     4288                        |
|0390|05|09|I64   |     108208                      |
|0391|05|12|STRUCT|     {                           |
|0392|06|01|BINARY|      test⁠test‫             |
|0393|06|02|BINARY|                                 |
|0394|06|03|I64   |      6                          |
|0395|05|03|STOP  |     }                           |
|0396|04|03|STOP  |    }                            |
|0397|03|03|STOP  |   }                             |
|0398|02|03|STOP  |  }                              |
|0399|02|02|I64   |  112492                         |
|0400|02|03|I64   |  1000                           |
|0401|01|03|STOP  | }                               |
|0402|00|03|STOP  |}                                |
|0403|00|06|BINARY|parquet-mr version 1.8.1 (build  |
|0404|00|06|STOP  |}                                |
</details>
