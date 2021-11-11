/* ... */
#ifndef LAPYS
# define LAPYS
  /* Pragmatic */
  #pragma once

  /* Import > ... */
  // : [C++ Standard Library]
  #include <cfloat>  // C Float
  #include <climits> // C Limits
  #include <cstddef> // C Standard Definition
  #include <cstdio>  // C Standard Input/ Output
  #include <cstdlib> // C Standard Library
  #include <new>     // New

  // : [C Standard Library]
  #include <errno.h>   // Error No.
  #include <stdbool.h> // Standard Booleans
  #include <stdint.h>  // Standard Integers
  #include <wchar.h>   // Wide Characters

  // : [...]
  #include "lapys/extensions.h"  // Extensions
  #include "lapys/macros.h"      // Macros
  #include "lapys/traits.hpp"    // Traits
  #include "lapys/constants.hpp" // Constants
  #include "lapys/parity.hpp"    // Parity
  #
  #include "lapys/memory.hpp"  // Memory
  #include "lapys/array.hpp"   // Array
  #include "lapys/string.hpp"  // String
  #include "lapys/program.hpp" // Program
  #
  #include "lapys/entry.hpp" // Entry

  /* Definitions > ... */
  #undef CPP_COMPILER
  # undef CPP__CLANG__COMPILER
  # undef CPP__GCC__COMPILER
  # undef CPP__ICC__COMPILER
  # undef CPP__MSVC__COMPILER
  #undef CPP_PREPROCESSOR
  # undef CPP_PREPROCESSOR_CHECK
  # undef CPP_PREPROCESSOR_SELECT
  # undef CPP_STANDARD_PREPROCESSOR
  # undef CPP__MSVC__PREPROCESSOR
  #undef CPP_VENDOR
  # undef CPP__APPLE_MACINTOSH__VENDOR
  # undef CPP__LINUX__VENDOR
  # undef CPP__MICROSOFT_WINDOWS__VENDOR
  # undef CPP__NINTENDO__VENDOR
  # undef CPP__UNIX__VENDOR
  #undef CPP_VERSION
  #undef LAPYS_MAX_ARITY
  #undef LAPYS_MAX_TEMPLATE_INSTANTIATION
  #
  #undef align
  #undef alignmentof
  #undef apply
  # undef apply_0
  # undef apply_1
  # undef apply_2
  # undef apply_3
  # undef apply_4
  # undef apply_5
  # undef apply_6
  # undef apply_7
  # undef apply_8
  # undef apply_9
  # undef apply_10
  # undef apply_11
  # undef apply_12
  # undef apply_13
  # undef apply_14
  # undef apply_15
  # undef apply_16
  # undef apply_17
  # undef apply_18
  # undef apply_19
  # undef apply_20
  # undef apply_21
  # undef apply_22
  # undef apply_23
  # undef apply_24
  # undef apply_25
  # undef apply_26
  # undef apply_27
  # undef apply_28
  # undef apply_29
  # undef apply_30
  # undef apply_31
  # undef apply_32
  # undef apply_33
  # undef apply_34
  # undef apply_35
  # undef apply_36
  # undef apply_37
  # undef apply_38
  # undef apply_39
  # undef apply_40
  # undef apply_41
  # undef apply_42
  # undef apply_43
  # undef apply_44
  # undef apply_45
  # undef apply_46
  # undef apply_47
  # undef apply_48
  # undef apply_49
  # undef apply_50
  # undef apply_51
  # undef apply_52
  # undef apply_53
  # undef apply_54
  # undef apply_55
  # undef apply_56
  # undef apply_57
  # undef apply_58
  # undef apply_59
  # undef apply_60
  # undef apply_61
  # undef apply_62
  # undef apply_63
  # undef apply_64
  # undef apply_65
  # undef apply_66
  # undef apply_67
  # undef apply_68
  # undef apply_69
  # undef apply_70
  # undef apply_71
  # undef apply_72
  # undef apply_73
  # undef apply_74
  # undef apply_75
  # undef apply_76
  # undef apply_77
  # undef apply_78
  # undef apply_79
  # undef apply_80
  # undef apply_81
  # undef apply_82
  # undef apply_83
  # undef apply_84
  # undef apply_85
  # undef apply_86
  # undef apply_87
  # undef apply_88
  # undef apply_89
  # undef apply_90
  # undef apply_91
  # undef apply_92
  # undef apply_93
  # undef apply_94
  # undef apply_95
  # undef apply_96
  # undef apply_97
  # undef apply_98
  # undef apply_99
  # undef apply_100
  # undef apply_101
  # undef apply_102
  # undef apply_103
  # undef apply_104
  # undef apply_105
  # undef apply_106
  # undef apply_107
  # undef apply_108
  # undef apply_109
  # undef apply_110
  # undef apply_111
  # undef apply_112
  # undef apply_113
  # undef apply_114
  # undef apply_115
  # undef apply_116
  # undef apply_117
  # undef apply_118
  # undef apply_119
  # undef apply_120
  # undef apply_121
  # undef apply_122
  # undef apply_123
  # undef apply_124
  # undef apply_125
  # undef apply_126
  # undef apply_127
  # undef apply_128
  # undef apply_129
  # undef apply_130
  # undef apply_131
  # undef apply_132
  # undef apply_133
  # undef apply_134
  # undef apply_135
  # undef apply_136
  # undef apply_137
  # undef apply_138
  # undef apply_139
  # undef apply_140
  # undef apply_141
  # undef apply_142
  # undef apply_143
  # undef apply_144
  # undef apply_145
  # undef apply_146
  # undef apply_147
  # undef apply_148
  # undef apply_149
  # undef apply_150
  # undef apply_151
  # undef apply_152
  # undef apply_153
  # undef apply_154
  # undef apply_155
  # undef apply_156
  # undef apply_157
  # undef apply_158
  # undef apply_159
  # undef apply_160
  # undef apply_161
  # undef apply_162
  # undef apply_163
  # undef apply_164
  # undef apply_165
  # undef apply_166
  # undef apply_167
  # undef apply_168
  # undef apply_169
  # undef apply_170
  # undef apply_171
  # undef apply_172
  # undef apply_173
  # undef apply_174
  # undef apply_175
  # undef apply_176
  # undef apply_177
  # undef apply_178
  # undef apply_179
  # undef apply_180
  # undef apply_181
  # undef apply_182
  # undef apply_183
  # undef apply_184
  # undef apply_185
  # undef apply_186
  # undef apply_187
  # undef apply_188
  # undef apply_189
  # undef apply_190
  # undef apply_191
  # undef apply_192
  # undef apply_193
  # undef apply_194
  # undef apply_195
  # undef apply_196
  # undef apply_197
  # undef apply_198
  # undef apply_199
  # undef apply_200
  # undef apply_201
  # undef apply_202
  # undef apply_203
  # undef apply_204
  # undef apply_205
  # undef apply_206
  # undef apply_207
  # undef apply_208
  # undef apply_209
  # undef apply_210
  # undef apply_211
  # undef apply_212
  # undef apply_213
  # undef apply_214
  # undef apply_215
  # undef apply_216
  # undef apply_217
  # undef apply_218
  # undef apply_219
  # undef apply_220
  # undef apply_221
  # undef apply_222
  # undef apply_223
  # undef apply_224
  # undef apply_225
  # undef apply_226
  # undef apply_227
  # undef apply_228
  # undef apply_229
  # undef apply_230
  # undef apply_231
  # undef apply_232
  # undef apply_233
  # undef apply_234
  # undef apply_235
  # undef apply_236
  # undef apply_237
  # undef apply_238
  # undef apply_239
  # undef apply_240
  # undef apply_241
  # undef apply_242
  # undef apply_243
  # undef apply_244
  # undef apply_245
  # undef apply_246
  # undef apply_247
  # undef apply_248
  # undef apply_249
  # undef apply_250
  # undef apply_251
  # undef apply_252
  # undef apply_253
  # undef apply_254
  # undef apply_255
  #undef concatenate
  #undef constfunc
  # undef constfunc_false
  # undef constfunc_true
  #undef constvar
  #undef defer
  # undef defer_parse
  #undef deleted
  #undef exceptof
  #undef exceptspec
  # undef exceptspec_fail
  # undef exceptspec_pass
  #   undef exceptspec_check_true
  #undef final
  #undef first
  #undef lvalued
  #undef nodecay
  #undef noexcept
  #undef noinline
  #undef noreturn
  #undef nouniqueaddr
  #undef rvalued
#endif
