let find_safe = (fn: 'a => bool, list: list('a)) : option('a) =>
  switch (List.find(fn, list)) {
  | result => Some(result)
  | exception Not_found => None
  };

let assoc_safe =  (key: 'a, values: list(('a, 'b))) : option('b) =>
  switch (List.assoc(key, values)) {
  | result => Some(result)
  | exception Not_found => None
  };

let assq_safe =  (key: 'a, values: list(('a, 'b))) : option('b) =>
  switch (List.assq(key, values)) {
  | result => Some(result)
  | exception Not_found => None
  };
