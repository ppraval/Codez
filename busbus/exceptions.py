try:
raise ExceptionGroup('Example ExceptionGroup', (
TypeError('Example TypeError'),
ValueError('Example ValueError'),
KeyError('Example KeyError'),
AttributeError('Example AttributeError')
))
except* TypeError:
...
except* ValueError as e:
...
except* (KeyError, AttributeError) as e:
...
