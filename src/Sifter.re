type extractor('a) =
  'a => string;

type conjunctionType =
  | And
  | Or;

type sortOrder =
  | Ascending
  | Descending;

type sortField('a) = {
  field: 'a,
  order: sortOrder
};

type config('a) = {
  extractor: list(extractor('a)),
  limit: int,
  sort: option(sortField('a)),
  filter: bool,
  conjunction: conjunctionType,
  respectWordBoundaries: bool
};

type scoredResult('a) =
  (float, 'a);


let extractResults = (results: list(scoredResult('a))) : list('a) =>
  List.map(snd, results);

let rec take = (limit: int , results: list(scoredResult('a))) : list(scoredResult('a)) =>
  switch(results) {
  | [] => []
  | [_head, ...tail] =>
       if (List.length(results) == limit) {
         List.rev(results)
       } else {
         take(limit, tail)
       };
  };

let limitResults = (limit: int, results: list(scoredResult('a))) : list(scoredResult('a)) =>
  if (List.length(results) <= limit) {
    results
  } else {
    results
    |> List.rev
    |> take(limit)
  };

