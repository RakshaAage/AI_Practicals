greeting([hello, hi, hey, greetings, 'howdy!']).
response(hello, ['hi there!', 'hello!', 'hey!', 'nice to see you!', 'how are you?']).
response(hi, ['hello!', 'hey there!', 'hi!', 'how are you?', 'wharesponse('how are you?', ['I am fine, thank you!', 'I am doing well, thanks for asking!', 'I am good, how about you?', 'I am great, how are you?']).
response('what is the weather like?', ['It is sunny today.', 'Looks like it will rain.', 'The weather is pleasant.', 'It is cold outside.']).

response(_, ['I am not sure what you mean...', 'Could you please rephrase that?', 'I am just a simple chatbot...', 'I am not equipped to answer that.']).

respond(Query, Response) :-
    (var(Query) ->
        Response = ['I am not sure what you mean...', 'Could you please rephrase that?', 'I am just a simple chatbot...', 'I am not equipped to answer that.']
    ; response(Query, Response), !
    ).

chat :-
    write('Chatbot: Hello! How can I response('how are you?', ['I am fine, thank you!', 'I am doing well, thanks for asking!', 'I am good, how about you?', 'I am great, how are you?']).
response('what is the weather like?', ['It is sunny today.', 'Looks like it will rain.', 'The weather is pleasant.', 'It is cold outside.']).

response(_, ['I am not sure what you mean...', 'Could you please rephrase that?', 'I am just a simple chatbot...', 'I am not equipped to answer that.']).

respond(Query, Response) :-
    (var(Query) ->
        Response = ['I am not sure what you mean...', 'Could you please rephrase that?', 'I am just a simple chatbot...', 'I am not equipped to answer that.']
    ; response(Query, Response), !
    ).

chat :-
    write('Chatbot: Hello! How can I help you?'), nl,
    repeat,
    write('You: '),
    read_line_to_codes(user_input, Input),
    atom_codes(Query, Input),
    (Query = bye -> write('Chatbot: Goodbye!');
    (greeting(Query) -> random_member(Greeting, Query), write('Chatbot: '), write(Greeting), nl;
    respond(Query, Response), random_member(Reply, Response), write('Chatbot: '), write(Reply), nl, fail)),
    Query = bye, !.
