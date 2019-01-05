import agb.types

test_bf = agb.types.BitfieldType(
    'u16',
    [
        ('a', 'attacks', 9),
        ('b', None, 7)
    ]
)

test_fixed = agb.types.FixedSizeArrayType(
    'test.stru',
    lambda *args: 4
)

test_var = agb.types.VariableSizeArrayType(
    'test.stru',
    (1, ['length'])
)


test_stru = agb.types.Structure([
    ('a', 'u16'),
    ('b', 'u32'),
], hidden_members=set(['a']))

test_un = agb.types.UnionType(
    {'bitfield' : 'test.bf', 'structure' : 'test.stru'},
    lambda project, context, parents: 'bitfield' if int(parents[-2]['length']) > 0 else 'structure'
)

test_ub = agb.types.UnboundedArrayType(
    'test.un',
    {'a' : -1, 'b' : 3}
)

test_ptr = agb.types.PointerType(
    'test.ub',
     (lambda project, context, parents: ('test_label', 2, False))
)


test_super = agb.types.Structure([
    ('length', 'int'),
    ('data', 'test.ptr')
])

models_to_export = {
    'test.fixed' : test_fixed,
    'test.stru' : test_stru,
    'test.ptr' : test_ptr,
    'test.super' : test_super,
    'test.var' : test_var,
    'test.ub' : test_ub,
    'test.bf' : test_bf,
    'test.un' : test_un,
}
