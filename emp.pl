% Define the performance criteria
criteria(communication_skill).
criteria(teamwork_skill).
criteria(problem_solving_skill).
criteria(punctuality).
criteria(quality_of_work).

% Define the weights for each criterion
weight(communication_skill, 0.2).
weight(teamwork_skill, 0.2).
weight(problem_solving_skill, 0.2).
weight(punctuality, 0.2).
weight(quality_of_work, 0.2).

% Define employee performance based on the criteria
performance(john, communication_skill, 8).
performance(john, teamwork_skill, 7).
performance(john, problem_solving_skill, 9).
performance(john, punctuality, 9).
performance(john, quality_of_work, 8).

performance(lisa, communication_skill, 9).
performance(lisa, teamwork_skill, 8).
performance(lisa, problem_solving_skill, 8).
performance(lisa, punctuality, 9).
performance(lisa, quality_of_work, 9).

% Define rules to evaluate overall performance
evaluate_performance(Employee, Score) :-
    findall(CriterionScore, (
        performance(Employee, Criteria, Rating),
        weight(Criteria, Weight),
        CriterionScore is Rating * Weight
    ), CriterionScores),
    sum_list(CriterionScores, Score).

% Main predicate to get overall performance of an employee
get_performance(Employee, Score) :-
    evaluate_performance(Employee, Score).

% Example usage:
% get_performance(john, Score). % Evaluate John's performance
% get_performance(lisa, Score). % Evaluate Lisa's performance
