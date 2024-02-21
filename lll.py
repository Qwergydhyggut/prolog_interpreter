from collections import defaultdict

def closure(items, grammar):
    def find_production(production):
        # Find production in grammar

    def closure_of_production(production, lookaheads):
        # Calculate closure of a production

    closure_items = set(items)
    changed = True
    while changed:
        changed = False
        for item in list(closure_items):
            production = find_production(item)
            if production:
                lookaheads = item['lookaheads']
                new_items = closure_of_production(production, lookaheads)
                for new_item in new_items:
                    if new_item not in closure_items:
                        closure_items.add(new_item)
                        changed = True
    return closure_items

def goto(items, symbol, grammar):
    def find_production(production):
        # Find production in grammar

    goto_items = set()
    for item in items:
        production = find_production(item)
        if production:
            dot_index = item['production'].index('.')
            if dot_index < len(production) - 1 and production[dot_index + 1] == symbol:
                new_item = {
                    'production': production,
                    'index': dot_index + 1,
                    'lookaheads': item['lookaheads']
                }
                goto_items.add(new_item)
    return closure(goto_items, grammar)

def items(grammar):
    start_production = next(iter(grammar.values()))[0]
    start_item = {
        'production': ['.', *start_production],
        'index': 0,
        'lookaheads': ['$']
    }
    return closure({start_item}, grammar)

def construct_lr1_table(lr1_items, grammar):
    lr1_table = defaultdict(dict)
    for i, items in enumerate(lr1_items):
        items = list(items)
        for item in items:
            production = item['production']
            dot_index = item['index']
            lookahead = item['lookaheads'][0]
            if dot_index < len(production) - 1:
                symbol = production[dot_index + 1]
                goto_items = goto(items, symbol, grammar)
                if goto_items:
                    if symbol.islower():
                        lr1_table[i][(symbol, lookahead)] = ('shift', items.index(goto_items))
                    else:
                        lr1_table[i][(symbol, lookahead)] = ('goto', items.index(goto_items))
            else:
                if production != ['.', *next(iter(grammar.values()))[0]]:
                    for la in item['lookaheads']:
                        lr1_table[i][('', la)] = ('reduce', production)
                else:
                    lr1_table[i][('$', '$')] = ('accept',)
    return lr1_table

def lr1_parse(table, tokens):
    stack = [0]
    tokens.append('$')
    current_token = tokens.pop(0)
    while True:
        state = stack[-1]
        action = table[state][(current_token, tokens[0])]
        if action[0] == 'shift':
            stack.append(tokens.popleft())
            stack.append(action[1])
            current_token = tokens.pop(0)
        elif action[0] == 'reduce':
            for _ in action[1][1:]:
                stack.pop()
                state = stack[-1]
                stack.append(action[1][0])
                stack.append(table[state][(action[1][0], '')])
        elif action[0] == 'goto':
            stack.append(action[1])
        elif action[0] == 'accept':
            return "Accepted"
        else:
            return "Error"

# 示例文法
grammar = {
    'S': [['A', 'B']],
    'A': [['a', 'A'], ['']],
    'B': [['b']]
}

lr1_items = items(grammar)
lr1_table = construct_lr1_table(lr1_items, grammar)
input_tokens = ['a', 'b']

lr1_parse(lr1_table, input_tokens)
