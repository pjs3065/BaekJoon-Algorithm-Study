package test;

import java.util.Scanner;

public class line1 {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		// input
		int t = scan.nextInt();
		int count = 1;

		while (count <= t) {
			int n = scan.nextInt();

			int[] x = new int[n];
			int[] y = new int[n];
			String[] team_name = new String[n];

			for (int i = 0; i < n; i++) {
				x[i] = scan.nextInt();
				y[i] = scan.nextInt();
				team_name[i] = scan.next();
			}

			// calculate each team minimum distance

			double brown_team_min = 9999;
			double cony_team_min = 9999;

			double[] distance = new double[n];

			for (int i = 0; i < n; i++) {

				distance[i] = getDistance(0, 0, x[i], y[i]);

				if (team_name[i].equals("Brown")) {
					if (brown_team_min > distance[i]) {
						brown_team_min = distance[i];
					}
				}

				else {
					if (cony_team_min > distance[i]) {
						cony_team_min = distance[i];
					}
				}
			}

			// Winner team name
			String win_team_name = (brown_team_min < cony_team_min ? "Brown" : "Cony");
			int winner_score = 0;

			// loser team distance
			double lose_team_distance = (brown_team_min < cony_team_min ? cony_team_min : brown_team_min);

			// Score calculate
			for (int i = 0; i < n; i++) {
				if (lose_team_distance > distance[i]) {
					winner_score += 1;
				}
			}

			// Output
			System.out.println(win_team_name + " " + winner_score);
			count++;
		}

	}

	static double getDistance(int x, int y, int x1, int y1) {
		return Math.sqrt(Math.pow(Math.abs(x1 - x), 2) + Math.pow(Math.abs(y1 - y), 2));
	}
}
