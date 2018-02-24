let index_safe =  (str: string, ch: char) : option(int) =>
  switch (String.index(str, ch)) {
  | result => Some(result)
  | exception Not_found => None
  };

let rindex_safe =  (str: string, ch: char) : option(int) =>
  switch (String.rindex(str, ch)) {
  | result => Some(result)
  | exception Not_found => None
  };

let index_from =  (str: string, index: int, ch: char) : option(int) =>
  switch (String.index_from(str, index, ch)) {
  | result => Some(result)
  | exception Not_found => None
  };

let rindex_from =  (str: string, index: int, ch: char) : option(int) =>
  switch (String.rindex_from(str, index, ch)) {
  | result => Some(result)
  | exception Not_found => None
  };
