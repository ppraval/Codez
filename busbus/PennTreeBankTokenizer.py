import nltk

text = 'That U.S.A. poster-print costs $12.40...'

# pattern = r'''(?x)              # enable verbose mode
#     ([A-Z]\.)+                  # abbreviations like U.S.A.
#   | \w+(-\w+)*                  # words with optional internal hyphens
#   | \$?\d+(\.\d+)?%?            # currency and percentages like $12.40, 82%
#   | \.\.\.                      # ellipsis
#   | [][.,;"'?():-_`]           # separate punctuation tokens
# '''


pattern = r'''(?x)              # enable verbose mode
    (?:[A-Z]\.)+                # abbreviations like U.S.A.
  | \w+(?:-\w+)*                # words with optional internal hyphens
  | \$?\d+(?:\.\d+)?%?          # currency and percentages like $12.40, 82%
  | \.\.\.                      # ellipsis
  | [][.,;"'?():-_`]            # separate punctuation tokens
'''

tokens = nltk.regexp_tokenize(text, pattern)
print(tokens)