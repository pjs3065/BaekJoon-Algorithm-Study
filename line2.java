package test;

import java.util.Scanner;

public class line2 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		//input canvas, color, frame, no
		String canvas = scan.nextLine();
		String color = scan.nextLine();
		String frame = scan.nextLine();
		String no = scan.nextLine();

		//token works
		String[] token1 = canvas.split("\\s");
		String[] token2 = color.split("\\s");
		String[] token3 = frame.split("\\s");
		String[] token4 = no.split("\\s");

		// allocate value
		// canvas size
		int canvas_size_w = Integer.parseInt(token1[2]);
		int canvas_size_h = Integer.parseInt(token1[4]);

		// background color
		int background_color = Integer.parseInt(token2[2].replaceFirst("^0x", ""), 16);

		// frames
		int frames = Integer.parseInt(token3[3]);

		// input no option & token
		// each point values
		int width_p = 0;
		int height_p = 0;
		int alpha_p = 0;
		int duration_p = 0;

		for (int i = 0; i < 5; i++) {
			if (token4[i].equals("width")) {
				width_p = i;
			} else if (token4[i].equals("height")) {
				height_p = i;
			} else if (token4[i].equals("alpha")) {
				alpha_p = i;
			} else if (token4[i].equals("duration")) {
				duration_p = i;
			}
		}
		
		//option token work
		String[] option = new String[frames];

		int width[] = new int[frames];
		int height[] = new int[frames];
		int alpha[] = new int[frames];
		int duration[] = new int[frames];

		for (int i = 0; i < frames; i++) {
			option[i] = scan.nextLine();
		}

		// allocate option values
		for (int i = 0; i < frames; i++) {
			String[] token5 = option[i].split("\\s");

			width[i] = Integer.parseInt(token5[width_p]);
			height[i] = Integer.parseInt(token5[height_p]);
			alpha[i] = (token5[alpha_p].equals("yes") ? 1 : 0);
			duration[i] = Integer.parseInt(token5[duration_p]);
		}

		// output
		System.out.println(canvas_size_w);
		System.out.println(canvas_size_h);
		System.out.println(background_color);
		System.out.println(frames);

		for (int i = 0; i < frames; i++) {
			System.out.println(width[i] + "x" + height[i] + ", " + duration[i] + ", " + alpha[i]);
		}
	}
}
